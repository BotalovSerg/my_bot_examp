import tkinter as tk
from tkinter import filedialog, scrolledtext, messagebox
import threading
import os
import docx
from sentence_transformers import SentenceTransformer
import faiss
import numpy as np
import pickle


# --- КЛАСС ДЛЯ ОБРАБОТКИ ФАЙЛА (БЭКЕНД) ---
# Мы вынесли всю логику в отдельный класс для чистоты кода.
class RAGProcessor:
    def __init__(self, log_callback):
        self.log_callback = log_callback
        self.model = None

    def load_model(self):
        """Загружает модель для создания эмбеддингов. Может занять время."""
        if self.model is None:
            self.log_callback(
                "Загрузка AI-модели (sentence-transformers)... Это может занять несколько минут при первом запуске."
            )
            # Используем популярную мультиязычную модель
            self.model = SentenceTransformer("all-MiniLM-L6-v2")
            self.log_callback("Модель успешно загружена.")
        return True

    def _read_docx(self, filepath):
        """Читает текст из .docx файла."""
        doc = docx.Document(filepath)
        full_text = [para.text for para in doc.paragraphs if para.text.strip()]
        return "\n".join(full_text)

    def _chunk_text(self, text, chunk_size=250, overlap=30):
        """Разбивает текст на пересекающиеся фрагменты (чанки)."""
        words = text.split()
        if not words:
            return []
        chunks = [" ".join(words[i : i + chunk_size]) for i in range(0, len(words), chunk_size - overlap)]
        return chunks

    def process_file(self, filepath):
        """Полный цикл обработки файла."""
        try:
            self.log_callback(f"Начало обработки файла: {os.path.basename(filepath)}")

            # Шаг 1: Чтение и разбиение на чанки
            self.log_callback("Шаг 1/4: Чтение текста из документа...")
            text = self._read_docx(filepath)
            if not text:
                self.log_callback("Ошибка: Документ пустой или не удалось прочитать текст.", "error")
                return

            self.log_callback("Шаг 2/4: Разделение текста на фрагменты (чанки)...")
            chunks = self._chunk_text(text)
            self.log_callback(f"Документ разделен на {len(chunks)} фрагментов.")

            if not chunks:
                self.log_callback("Ошибка: Не удалось создать фрагменты из текста.", "error")
                return

            # Шаг 2: Создание эмбеддингов
            self.log_callback("Шаг 3/4: Создание векторов (эмбеддингов)... Это самый долгий этап.")
            embeddings = self.model.encode(chunks, show_progress_bar=True)
            self.log_callback("Векторы успешно созданы.")

            # Шаг 3: Создание и сохранение FAISS индекса
            self.log_callback("Шаг 4/4: Создание и сохранение файлов FAISS и PKL...")
            base_dir = os.path.dirname(filepath)
            base_filename = os.path.splitext(os.path.basename(filepath))[0]

            faiss_path = os.path.join(base_dir, f"{base_filename}_index.faiss")
            pkl_path = os.path.join(base_dir, f"{base_filename}_chunks.pkl")

            embedding_dim = embeddings.shape[1]
            index = faiss.IndexFlatL2(embedding_dim)
            index.add(np.array(embeddings).astype("float32"))

            faiss.write_index(index, faiss_path)
            self.log_callback(f"-> Индекс FAISS сохранен: {faiss_path}", "success")

            with open(pkl_path, "wb") as f:
                pickle.dump(chunks, f)
            self.log_callback(f"-> Фрагменты текста сохранены: {pkl_path}", "success")

            self.log_callback("\n🎉 Обработка успешно завершена!", "success")

        except Exception as e:
            self.log_callback(f"Произошла критическая ошибка: {e}", "error")


# --- КЛАСС ПРИЛОЖЕНИЯ (ИНТЕРФЕЙС) ---
class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Конвертер базы знаний для RAG")
        self.geometry("700x500")

        self.processor = RAGProcessor(self.log_message)

        # Стили для лога
        self.log_area = scrolledtext.ScrolledText(self, wrap=tk.WORD, state="disabled", font=("Arial", 10))
        self.log_area.pack(padx=10, pady=10, expand=True, fill="both")
        self.log_area.tag_config("info", foreground="black")
        self.log_area.tag_config("success", foreground="green", font=("Arial", 10, "bold"))
        self.log_area.tag_config("error", foreground="red")

        self.process_button = tk.Button(
            self, text="Выбрать .docx файл и обработать", command=self.start_processing
        )
        self.process_button.pack(padx=10, pady=10)

        # Предзагрузка модели при старте
        self.preload_model()

    def preload_model(self):
        """Запускает загрузку модели в отдельном потоке, чтобы не блокировать UI."""
        self.process_button.config(state="disabled", text="Загрузка AI-модели...")
        thread = threading.Thread(target=self._model_loader_thread, daemon=True)
        thread.start()

    def _model_loader_thread(self):
        """Поток для загрузки модели."""
        success = self.processor.load_model()
        if success:
            self.process_button.config(state="normal", text="Выбрать .docx файл и обработать")

    def log_message(self, msg, tag="info"):
        """Потокобезопасный способ добавить сообщение в лог из любого потока."""

        def _update_log():
            self.log_area.config(state="normal")
            self.log_area.insert(tk.END, msg + "\n", tag)
            self.log_area.config(state="disabled")
            self.log_area.see(tk.END)  # Автопрокрутка вниз

        self.after(0, _update_log)

    def start_processing(self):
        """Открывает диалог выбора файла и запускает обработку в новом потоке."""
        filepath = filedialog.askopenfilename(
            title="Выберите .docx файл", filetypes=(("Word Documents", "*.docx"), ("All files", "*.*"))
        )
        if not filepath:
            self.log_message("Операция отменена пользователем.", "error")
            return

        self.log_area.config(state="normal")
        self.log_area.delete("1.0", tk.END)
        self.log_area.config(state="disabled")

        self.process_button.config(state="disabled")

        # Запускаем тяжелую задачу в отдельном потоке
        thread = threading.Thread(target=self.processing_thread_func, args=(filepath,), daemon=True)
        thread.start()

    def processing_thread_func(self, filepath):
        """Функция-обертка, выполняемая в потоке."""
        self.processor.process_file(filepath)
        # Когда обработка завершена, возвращаем кнопку в активное состояние
        self.process_button.config(state="normal")


if __name__ == "__main__":
    app = App()
    app.mainloop()
