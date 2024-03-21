from tkinter import *


food = ['apple', 'bananas', 'tomato', 'potato', 'carrot',
        'pineapple', 'bread', 'butter', 'milk', 'meat']

def buy(first, second):
    select = first.curselection()
    for i in select:
        second.insert(END, first.get(i))
    select = list(select)
    select.reverse()
    for i in select:
        first.delete(i)

root = Tk()

box_1 = Listbox(selectmode=EXTENDED)
box_1.pack(side=LEFT)
for i in food:
    box_1.insert(END, i)

box_2 = Listbox(selectmode=EXTENDED)
box_2.pack(side=RIGHT)

f = Frame()
f.pack(side=LEFT)

Button(f, text='>>>', command=lambda i=box_1, j=box_2: buy(i, j)).pack()
Button(f, text='<<<', command=lambda i=box_2, j=box_1: buy(i, j)).pack()




root.mainloop()