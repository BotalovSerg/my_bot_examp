from tkinter import *


root = Tk()
# f_top = Frame(root)
# f_bot = Frame(root)

f_top = LabelFrame(root, text='Top')
f_bot = LabelFrame(root, text='Bot')


l1 = Label(f_top, width=7, height=4, bg='yellow', text='1')
l2 = Label(f_top, width=7, height=4, bg='orange', text='2')
l3 = Label(f_bot, width=7, height=4, bg='lightgreen', text='3')
l4 = Label(f_bot, width=7, height=4, bg='lightblue', text='4')


f_top.pack(padx=20, pady=20)
f_bot.pack(ipadx=20, ipady=20)
l1.pack(side=LEFT)
l2.pack(side=LEFT)
l3.pack(side=LEFT)
l4.pack(side=LEFT)


root.mainloop()