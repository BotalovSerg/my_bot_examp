import tkinter as tk
from text_editor import TextEditor
from settings import *


class Notebook(tk.Tk):
    def __init__(self):
        super().__init__()
        self.geometry(f'{WIDTN_WINDOW}x{HEIGHT_WINDOW}')
        self.title(TITLE)
        self.init_text_editor()
        self.label = tk.Label(self, text='Label', bg='yellow')
        self.label.pack()

    def init_text_editor(self):
        self.text_editor = TextEditor(self)
        self.text_editor.pack(expand=1, fill=tk.BOTH)

if __name__ == '__main__':
    notebook = Notebook()
    notebook.mainloop()