import tkinter as tk




class TextEditor(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.config(borderwidth=1, relief='solid', padx=2, pady=2)
        self.text_editor = tk.Text(self, bg='black', fg='#66cce8', padx=10, pady=10,
                                   wrap=tk.WORD, insertbackground='brown', selectbackground='#8D917A',
                                   spacing3=10, width=30, font=('Cascadia Code', 12))
        self.text_editor.pack(fill=tk.BOTH)

        # self.label = tk.Label(self, text='Label', bg='yellow')
        # self.label.pack(fill=tk.BOTH)