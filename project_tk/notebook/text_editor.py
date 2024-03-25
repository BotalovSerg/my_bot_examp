from tkinter import *



class TextEditor:
    def __init__(self, master) -> None:
        self.frame = Frame(master)
        self.frame.pack(fill=BOTH, expand=1)
        self.text = Text(self.frame, bg='black', fg='lime', padx=10, pady=10,
                         wrap=WORD, insertbackground='brown', selectbackground='#8D917A',
                         spacing3=10, width=30)
        self.text.pack(expand=1, fill=BOTH, side=LEFT)
        self.scroll = Scrollbar(self.frame, command=self.text.yview)
        self.scroll.pack(side=LEFT, fill=Y)
        self.text.config(yscrollcommand=self.scroll.set)