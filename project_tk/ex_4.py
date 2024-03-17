from tkinter import *

def insert_text():
    s = "Hello World"
    text.insert(1.0, s)

def get_text():
    s = text.get(1.0, END)
    label['text'] = s

def delete_text():
    text.delete(1.0, END)


root = Tk()
# f_top = Frame(root)
# f_bot = Frame(root)

f_top = LabelFrame(root, text='Top')
f_bot = LabelFrame(root, text='Bot')


l1 = Label(f_top, width=7, height=4, bg='yellow', text='1')
l2 = Label(f_top, width=7, height=4, bg='orange', text='2')
l3 = Label(f_bot, width=7, height=4, bg='lightgreen', text='3')
l4 = Label(f_bot, width=7, height=4, bg='lightblue', text='4')


f_top.pack(padx=20, pady=20)
f_bot.pack(ipadx=20, ipady=20)
l1.pack(side=LEFT)
l2.pack(side=LEFT)
l3.pack(side=LEFT)
l4.pack(side=LEFT)

text = Text(width=25, height=5)
text.pack()

frame = Frame()
frame.pack()
Button(frame, text='Insert', command=insert_text).pack(side=LEFT)
Button(frame, text='Get', command=get_text).pack(side=LEFT)
Button(frame, text='Delete', command=delete_text).pack(side=LEFT)

label = Label()
label.pack()

# scroll = Scrollbar(command=text.yview)
# scroll.pack(side=LEFT, fill=Y)

# text.config(yscrollcommand=scroll.set)


root.mainloop()