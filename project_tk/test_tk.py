from tkinter import * 



class Block:
    def __init__(self, master, func) -> None:
        self.ent = Entry(master, width=20)
        self.but = Button(master, text='Преобразователь')
        self.lab = Label(master, width=20, bg='black', fg='white')
        self.but['command'] = getattr(self, func)
        self.ent.pack()
        self.but.pack()
        self.lab.pack()

    def str_to_sort(self) -> None:
        s = self.ent.get().split()
        s.sort()
        self.lab['text'] = ' '.join(s)

    def str_reverse(self) -> None:
        s = self.ent.get().split()
        s.reverse()
        self.lab['text'] = ' '.join(s)

root = Tk()

fisrt_block = Block(root, 'str_to_sort')
second_block = Block(root, 'str_reverse')




# ent = Entry(root, width=20)
# but = Button(root, text="Text")
# lab = Label(root, width=20, bg='black', fg='white')

# def str_to_sort_list(event):
#     s = ent.get()
#     s = s.split()
#     s.sort()
#     lab['text'] = " ".join(s)

# but.bind('<Button-1>', str_to_sort_list)

# ent.pack()
# but.pack()
# lab.pack()


if __name__ == '__main__':
    root.mainloop()