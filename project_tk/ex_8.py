from tkinter import *

class CheckButton:
    def __init__(self, master, title) -> None:
        self.var = BooleanVar()
        self.var.set(False)
        self.title = title
        self.cb = Checkbutton(
            master,
            text=title, variable=self.var,
            onvalue=True, offvalue=False
        )
        self.cb.pack(side=LEFT)


# def ch_on():
#     for ch in checks:
#         ch.cb.select()

# def ch_off():
#     for ch in checks:
#         ch.cb.deselect()
def get_info():
    info = var.get()
    if info == 0:
        label['text'] = 'Name Vasia, phone: +7 922 365 85 21'
    elif info == 1:
        label['text'] = 'Name Petia, phone: +7 912 498 32 77'
    elif info == 2:
        label['text'] = 'Name Serg, phone: +7 999 578 66 33'

root = Tk()

frame_1 = Frame()
frame_1.pack(side=LEFT)

var = IntVar()
var.set(-1)
r_1 = Radiobutton(frame_1, text='Vasia', indicatoron=False, 
                  variable=var, value=0, width=10, 
                  height=3, command=get_info)
r_1.pack()

r_2 = Radiobutton(frame_1, text='Peta', indicatoron=False,
                   variable=var, value=1, width=10, height=3,
                     command=get_info)
r_2.pack()

r_3 = Radiobutton(frame_1, text='Serg', indicatoron=False, 
                  variable=var, value=2, width=10, 
                  height=3, command=get_info)
r_3.pack()



label = Label(bg='white', width=50)
label.pack(side=LEFT, fill=Y)

# f1 = Frame()
# f1.pack(padx=10, pady=10)

# checks = []

# for i in range(10):
#     checks.append(CheckButton(f1, i))

# f2 = Frame()
# f2.pack()

# btn_on = Button(f2, text='ALL ON', command=ch_on)
# btn_on.pack(side=LEFT)
# btn_off = Button(f2, text='ALL OFF', command=ch_off)
# btn_off.pack(side=LEFT)

root.mainloop()