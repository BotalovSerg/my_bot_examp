from tkinter import *

root = Tk()


def change_side(event):
    if ew.get().isdigit():
        t['width'] = ew.get()
    if eh.get().isdigit():
        t['height'] = eh.get()

# def bg_color(event, color):
#     t['bg'] = color

# def grey_color(event):
#     t['bg'] = 'lightgrey'

f1 = Frame()
f1.pack()

f = Frame(f1)
f.pack(side=LEFT)
ew = Entry(f, width=3)
ew.pack()
ew.focus_set()
eh = Entry(f, width=3)
eh.pack()

b = Button(f1, text='Change')
b.pack(side=LEFT)
b.bind('<Button-1>', change_side)
b.bind('<Return>', change_side)
ew.bind('<Return>', change_side)
eh.bind('<Return>', change_side)

f2 = Frame()
f2.pack()

t = Text(f2, width=20, height=10, bg='lightgrey')
t.pack()
# t.bind('<FocusIn>', lambda event, i='white': bg_color(event, i))
# t.bind('<FocusOut>', lambda event, i='lightgrey': bg_color(event, i))

t.bind('<FocusIn>', lambda event, i='white': t.config(bg=i))
t.bind('<FocusOut>', lambda event, i='lightgrey': t.config(bg=i))


root.mainloop()