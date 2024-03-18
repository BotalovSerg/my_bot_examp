from tkinter import *

def change():
    if var.get() == 0:
        label['bg'] = 'red'
    elif var.get() == 1:
        label['bg'] = 'green'
    elif var.get() == 2:
        label['bg'] = 'blue'


def black_label():
    label['bg'] = 'black'

def yellow_label():
    label['bg'] = 'yellow'

def paint(color):
        label['bg'] = color


class RBColor:
    def __init__(self, color: str, val: int) -> None:
        Radiobutton(text=color.capitalize(),
                    command=lambda i=color: paint(i),
                    variable=var,
                    value=val).pack()


root = Tk()

var = IntVar()
var.set(0)
label = Label(width=20, height=10, bg='yellow')
label.pack()

RBColor('red', 0)
RBColor('green', 1)
RBColor('blue', 2)

# red = Radiobutton(text='Red', variable=var, value=0)
# green = Radiobutton(text='Green', variable=var, value=1)
# blue = Radiobutton(text='Blue', variable=var, value=2)

# btn = Button(text='Change', command=change)


# red.pack()
# green.pack()
# blue.pack()
# btn.pack()



# Radiobutton(text='First', command=black_label, variable=var, value=3).pack()
# Radiobutton(text='Second', command=yellow_label, variable=var, value=4).pack()

# r_var = BooleanVar()
# r_var.set(False)
# r1 = Radiobutton(text='First', variable=var, value=3)
# r2 = Radiobutton(text='Second', variable=var, value=4)

# r1.pack(anchor=W)
# r2.pack(anchor=W)
root.mainloop()