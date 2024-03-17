from tkinter import *

def open_file():
    f = ent.get()
    text.delete(1.0, END)
    with open(f) as file:
        text.insert(1.0, file.read())

def save_file():
    f = ent.get()
    with open(f, 'w+') as file:
        s = text.get(1.0, END)
        file.write(s)
        text.delete(1.0, END)


root = Tk()

frame = Frame()
frame.pack()

ent = Entry(frame, width=20)
ent.pack(side=LEFT, padx=5)
btn1 = Button(frame, text='Open', width=10, command=open_file)
btn2 = Button(frame, text='Save', width=10, command=save_file)
btn1.pack(side=LEFT)
btn2.pack(side=LEFT, padx=5)

frame_2 = Frame()
frame_2.pack()
text = Text(frame_2, width=50, height=20, wrap=NONE)
text.pack(side=LEFT)

scroll = Scrollbar(frame_2, command=text.yview)
scroll.pack(side=LEFT, fill=Y)
text.config(yscrollcommand=scroll.set)

scroll_2 = Scrollbar(orient=HORIZONTAL, command=text.xview)
scroll_2.pack(side=BOTTOM, fill=X)
text.config(xscrollcommand=scroll_2.set)

root.mainloop()