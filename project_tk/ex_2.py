from tkinter import *
from random import *

root = Tk()
root.title('Камень ножницы бумага')
root.geometry('600x400')
root.resizable(width=False, height=False)
root['bg'] = 'black'


def game():
    knb = ['Камень', 'Ножницы', 'Бумага']
    value = choice(knb)
    labelText.configure(text=value)


labelText = Label(root, text='', fg='white', font=('Comic Sans MS', 20), bg='black')
labelText.place(y=200, x=240)


btn_stone = Button(root,
             text='Камень',
             font=('Comic Sans MS', 20),
             bg='white',
             command=game)

btn_stone.place(x=50, y=300)

btn_scissors = Button(root,
             text='Ножницы',
             font=('Comic Sans MS', 20),
             bg='white',
             command=game)

btn_scissors.place(x=220, y=300)

btn_paper = Button(root,
             text='Бумага',
             font=('Comic Sans MS', 20),
             bg='white',
             command=game)

btn_paper.place(x=420, y=300)


if __name__ == '__main__':
    root.mainloop()