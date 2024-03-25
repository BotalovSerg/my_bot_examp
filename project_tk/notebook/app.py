from tkinter import *
from text_editor import TextEditor
from main_menu import MainMenu


root = Tk()
root.title('Notebook')
root.geometry('600x700')

text = TextEditor(root)
MainMenu(root, text)

if __name__ == '__main__':
    root.mainloop()


