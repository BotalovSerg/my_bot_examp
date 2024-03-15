from tkinter import *


class MathButton:
    def __init__(self, action) -> None:
        self.but = Button(text=action, width=10, command=self.math)
        self.operator = action
        self.but.pack()
    
    def math(self):
        try:
            n1 = float(ent_n1.get())
            n2 = float(ent_n2.get())
        except ValueError:
            lab_result['text'] = 'Error'
        else:
            if self.operator == '+':
                lab_result['text'] = n1 + n2
            
            elif self.operator == '-':
                lab_result['text'] = round(n1 - n2, 2)

            elif self.operator == '*':
                lab_result['text'] = round(n1 * n2, 2)
            
            elif self.operator == '/':
                if n2:                    
                    lab_result['text'] = round(n1 / n2, 2)
                else:
                    lab_result['text'] = 'ZeroDivisionError'


root = Tk()


ent_n1 = Entry(width=10)
ent_n1.pack()
ent_n2 = Entry(width=10)
ent_n2.pack()

but_summa = MathButton('+')
but_diff = MathButton('-')
but_mult = MathButton('*')
but_div = MathButton('/')

lab_result = Label(width=15)
lab_result.pack()


# ent_1 = Entry(root, width=10)
# ent_2 = Entry(root, width=10)

# bnt_1 = Button(root, text='+', width=12)
# bnt_2 = Button(root, text='-', width=12)
# bnt_3 = Button(root, text='*', width=12)
# bnt_4 = Button(root, text='/', width=12)

# lab_total = Label(root, width=15)

# ent_1.pack()
# ent_2.pack()
# bnt_1.pack()
# bnt_2.pack()
# bnt_3.pack()
# bnt_4.pack()
# lab_total.pack()


# def add_nums(event):
#     num_1 = ent_1.get()
#     num_2 = ent_2.get()
#     if num_1.isalpha() or num_2.isalpha():
#         lab_total['text'] = 'Error'
#         return
#     res = int(num_1) + int(num_2)
#     lab_total['text'] = res

# bnt_1.bind('<Button-1>', add_nums)


# def sub_nums(event):
#     num_1 = ent_1.get()
#     num_2 = ent_2.get()
#     if num_1.isalpha() or num_2.isalpha():
#         lab_total['text'] = 'Error'
#         return
#     res = int(num_1) - int(num_2)
#     lab_total['text'] = res

# bnt_2.bind('<Button-1>', sub_nums)


# def mult_nums(event):
#     num_1 = ent_1.get()
#     num_2 = ent_2.get()
#     if num_1.isalpha() or num_2.isalpha():
#         lab_total['text'] = 'Error'
#         return
#     res = int(num_1) * int(num_2)
#     lab_total['text'] = res

# bnt_3.bind('<Button-1>', mult_nums)


# def div_nums(event):
#     num_1 = ent_1.get()
#     num_2 = ent_2.get()
#     if num_1.isalpha() or num_2.isalpha():
#         lab_total['text'] = 'Error'
#         return
#     if num_2 == 0:
#         lab_total['text'] = 'Error'
#         return
#     res = int(num_1) / int(num_2)
#     lab_total['text'] = res

# bnt_4.bind('<Button-1>', div_nums)



root.mainloop()