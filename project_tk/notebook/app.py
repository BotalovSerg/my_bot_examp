from tkinter import *
from text_editor import TextEditor
from main_menu import MainMenu




def main():
    root = Tk()
    root.title('Notebook')
    root.geometry('600x700')

    text = TextEditor(root)
    MainMenu(root, text)
    root.mainloop()


if __name__ == '__main__':
    main()

