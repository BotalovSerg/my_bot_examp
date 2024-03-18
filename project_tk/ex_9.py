from tkinter import *


def add_item():
    box.insert(END, entry.get())
    entry.delete(0, END)

def del_list():
    select = list(box.curselection())
    select.reverse()
    print(select)
    for i in select:
        box.delete(i)

def save_list():
    f = open('list000.txt', 'w+')
    f.writelines('\n'.join(box.get(0, END)))
    f.close()



root = Tk()

box = Listbox(selectmode=EXTENDED)
box.pack(side=LEFT)
scroll = Scrollbar(command=box.yview)
scroll.pack(side=LEFT, fill=Y)
box.config(yscrollcommand=scroll.set)

f = Frame()
f.pack(side=LEFT, padx=10)
entry = Entry(f)
entry.pack(anchor=N)
Button(f, text='Add', command=add_item).pack(fill=X)
Button(f, text='Delete', command=del_list).pack(fill=X)
Button(f, text='Save', command=save_list).pack(fill=X)


root.mainloop()