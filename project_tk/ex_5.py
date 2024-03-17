from tkinter import *

def smile():
    label = Label(text=':)', bg='yellow')
    text.window_create(INSERT, window=label)

root = Tk()

text = Text(width=50, height=10)
text.pack()
# text.insert(1.0, "Hello world!\nline two")
# text.tag_add('title', 1.0, '1.end')
# text.tag_config('title', justify=CENTER, font=('Verdana', 24, 'bold'))
btn = Button(text=':)', command=smile)
btn.pack()


root.mainloop()