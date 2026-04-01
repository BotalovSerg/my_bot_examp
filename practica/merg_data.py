import json
from pathlib import Path
import os

# --- НАСТРОЙКИ ---
INPUT_FOLDER = "/home/botalov/Загрузки/scheduler"
OUTPUT_FILE = "merged_data_scheduler.json"
# -----------------


def merge_json_files():
    input_path = Path(INPUT_FOLDER)

    if not input_path.exists():
        print(f"Ошибка: Папка '{INPUT_FOLDER}' не найдена.")
        return

    # Получаем список всех json файлов
    json_files = list(input_path.glob("*.json"))
    total_files = len(json_files)

    print(f"Найдено файлов для обработки: {total_files}")

    if total_files == 0:
        print("Файлы не найдены.")
        return

    merged_data = []

    # Проходим по всем файлам
    for i, file_path in enumerate(json_files, 1):
        try:
            with open(file_path, "r", encoding="utf-8") as f:
                # Загружаем объект из файла
                data = json.load(f)
                merged_data.append(data)
        except json.JSONDecodeError as e:
            print(f"Ошибка JSON в файле {file_path}: {e}")
        except Exception as e:
            print(f"Неизвестная ошибка с файлом {file_path}: {e}")

        # Выводим прогресс каждые 1000 файлов, чтобы видеть, что скрипт работает
        if i % 1000 == 0:
            print(f"Обработано {i} из {total_files}...")

    # Записываем итоговый массив в один файл
    print("Запись в итоговый файл...")
    try:
        with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
            # ensure_ascii=False нужен для корректного отображения кириллицы (имена, комментарии)
            json.dump(merged_data, f, ensure_ascii=False, indent=2)
        print(f"Готово! Все данные сохранены в {OUTPUT_FILE}")
    except Exception as e:
        print(f"Ошибка при записи итогового файла: {e}")


if __name__ == "__main__":
    merge_json_files()
