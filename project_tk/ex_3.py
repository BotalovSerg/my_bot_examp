from tkinter import *
from datetime import datetime as dt


def change():
    b1['text'] = 'Изменено'
    b1['bg'] = '#000000'
    b1['fg'] = '#ffffff'
    b1['activebackground'] = '#555555'
    b1['activeforeground'] = '#ffffff'

def take():
    lab['text'] = 'Выдано'

def insert_time():
    t = dt.now().time()
    e1.insert(0, t.strftime('%H:%M:%S   '))


root = Tk()

e1 = Entry(width=50)
but = Button(text='Time', command=insert_time)
e1.pack()
but.pack()


b1 = Button(text='Изменить', width=15, height=3)
b1.config(command=change)
b1.pack()

Label(text='Пункт выдачи').pack()
Button(text='Взять', command=take).pack()
lab = Label(width=10, height=1)
lab.pack()


l1 = Label(text='Machine learning', font='Arial 32')
l2 = Label(text='Pattern recognition', font=('Comic Sans MS', 24, 'bold'))

l1.config(bd=20, bg='#ffaaaa')
l2.config(bd=20, bg='#aaffff')
l1.pack()
l2.pack()

root.mainloop()
