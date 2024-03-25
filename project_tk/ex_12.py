from tkinter import *

def exit_win(event):
    root.destroy()

def to_label(event):
    t = ent.get()
    lbl.configure(text=t)

def select_all(event):
    def select_all2(widget):
        widget.selection_range(0, END)
        widget.icursor(END)
    root.after(10, select_all2, event.widget)


root = Tk()

ent = Entry(width=40)
ent.focus_set()
ent.pack()

lbl = Label(height=3, fg='orange', bg='darkgreen', font='Verdana 24')
lbl.pack(fill=X)

ent.bind('<Return>', to_label)
ent.bind('<Control-a>', select_all)
root.bind('<Control-q>', exit_win)

root.mainloop()