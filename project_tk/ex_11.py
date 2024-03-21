from tkinter import *

def b1(event):
    root.title('Left button mouse')

def b3(event):
    root.title('Right button mouse')

def move(event):
    x = event.x
    y = event.y
    s = "Move mouse {} x {}".format(x, y)
    root.title(s)

def event_info(event):
    print(type(event))
    print(event)
    print(event.time)
    print(event.x_root)
    print(event.y_root)


def enter_leave(event):
    if event.type == '7':
        event.widget['text'] = 'In'
    elif event.type == '8':
        event.widget['text'] = 'Out'


root = Tk()
root.minsize(width=500, height=400)

# root.bind('<Button-1>', b1)
# root.bind('<Button-3>', b3)
# root.bind('<Motion>', move)
root.bind('<a>', event_info)

lab1 = Label(width=20, height=3, bg='white')
lab1.pack()
lab1.bind('<Enter>', enter_leave)
lab1.bind('<Leave>', enter_leave)

lab2 = Label(width=20, height=3, bg='black', fg='white')
lab2.pack()
lab2.bind('<Enter>', enter_leave)
lab2.bind('<Leave>', enter_leave)


root.mainloop()