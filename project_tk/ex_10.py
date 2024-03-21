from tkinter import *

root = Tk()

class RedButton:
    def __init__(self) -> None:
        self.b = Button(text='RED', width=10, height=3)
        self.b.bind('<Button-1>', self.change)
        self.b.pack()


    def change(self, event):
        self.b['fg'] = 'red'
        self.b['activeforeground'] = 'red'


# RedButton()
        
def enter_clik(event):
    s = ent.get()
    box.insert(END, s)
    ent.delete(0, END)

def double_clic(event):
    indx = box.curselection()
    if indx:
        s = box.get(indx[0])
        ent.delete(0, END)
        ent.insert(0, s)


ent = Entry(width=15)
ent.bind('<Return>', enter_clik)
ent.pack(side=LEFT)
box = Listbox()
box.bind('<Double-Button-1>', double_clic)
box.pack(side=RIGHT)



root.mainloop()