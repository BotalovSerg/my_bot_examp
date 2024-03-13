from tkinter import *

root = Tk()
root.title('Project')
root.geometry('600x600')
root.resizable(width=False, height=False)
root['bg'] = 'black'

def click():
    print('Hello')

btn = Button(
    root, 
    text='Power button', 
    command=click,
    font=('Comic Sons MS', 10, 'italic'),
    bg='lime',
    activebackground='red',
    activeforeground='white'
    )
btn.pack()


root.mainloop()