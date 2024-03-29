from tkinter import *
from text_editor import TextEditor
from main_menu import MainMenu
from hot_keys import exit_win

def window_search(event, ent):
    print(event)    
    ent.focus_set()
    ent.pack()




def main():
    root = Tk()
    root.title('Notebook')
    root.geometry('600x700')
    ent = Entry(width=40)   
    ent.pack()
    root.bind('<Control-f>', lambda e, ent=ent: window_search(e, ent))
    root.bind('<Control-q>', lambda e, r=root: exit_win(e, r))

    # ent = Entry(width=20)

    text = TextEditor(root)
    MainMenu(root, text)
    
    
    

    root.mainloop()


if __name__ == '__main__':
    main()

