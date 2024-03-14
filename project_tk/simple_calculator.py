from tkinter import *

class SimpleCalculator:
    def __init__(self, master, func) -> None:
        self.ent_1 = Entry(root, width=10)
        self.ent_2 = Entry(root, width=10)
        self.bnt_1 = Button(root, text='+', width=12)
        self.bnt_2 = Button(root, text='-', width=12)
        self.bnt_3 = Button(root, text='*', width=12)
        self.bnt_4 = Button(root, text='/', width=12)
        self.lab_total = Label(root, width=15)
        self.ent_1.pack()
        self.ent_2.pack()
        self.bnt_1.pack()
        self.bnt_2.pack()
        self.bnt_3.pack()
        self.bnt_4.pack()
        self.lab_total.pack()

    def calculator(self):
        num_1 = ent_1.get()
        num_2 = ent_2.get()
        res = int(num_1) + int(num_2)
        lab_total['text'] = res
        
root = Tk()

ent_1 = Entry(root, width=10)
ent_2 = Entry(root, width=10)

bnt_1 = Button(root, text='+', width=12)
bnt_2 = Button(root, text='-', width=12)
bnt_3 = Button(root, text='*', width=12)
bnt_4 = Button(root, text='/', width=12)

lab_total = Label(root, width=15)

ent_1.pack()
ent_2.pack()
bnt_1.pack()
bnt_2.pack()
bnt_3.pack()
bnt_4.pack()
lab_total.pack()

'a'.isalpha

def add_nums(event):
    num_1 = ent_1.get()
    num_2 = ent_2.get()
    if num_1.isalpha() or num_2.isalpha():
        lab_total['text'] = 'Error'
        return
    res = int(num_1) + int(num_2)
    lab_total['text'] = res

bnt_1.bind('<Button-1>', add_nums)



root.mainloop()