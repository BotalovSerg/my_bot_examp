from tkinter import *

db = {
    'Вася': '+7 922 365 85 2',
    'Serg': '+7 912 498 32 7',
    'Piter': '+7 999 578 66 33'
}

class RadioIndicatorOff:
    __val = 0

    def __init__(self, master, person) -> None:
        RadioIndicatorOff.__val += 1
        self.name = person
        self.rb = Radiobutton(master, text=person, width=10,
                              height=3, indicatoron=False,
                              variable=var,
                              value=RadioIndicatorOff.__val,
                              command=self.get_phone)
        self.rb.pack()

    def get_phone(self):
        label['text'] = db[self.name]

root = Tk()

f = Frame()
f.pack(side=LEFT)

var = IntVar()
var.set(-1)

for key in db.keys():
    RadioIndicatorOff(f, key)

label = Label(bg='white', width=20)
label.pack(side=LEFT, fill=Y)

root.mainloop()