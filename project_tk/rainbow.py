from tkinter import *




class ButtonRainbow:
    _rainbow = (('#ff0000', 'красный'), ('#ff7d00', 'оранжевый'),
                ('#ffff00', 'желтый'), ('#00ff00', 'зеленый'),
                ('#007dff', 'голубой'), ('#0000ff', 'синий'),
                ('#7d00ff', 'фиолетовый'))
    
    def __init__(self, i, color=None, hex_color=None) -> None:
        self.btn = Button(bg=ButtonRainbow._rainbow[i][0], width=15, command=self.clik)
        # self.btn.config(bg=hex_color, command=self.clik, width=15)
        self.color = self._rainbow[i][1]
        self.hex_color = self._rainbow[i][0]
        self.btn.pack()

    def clik(self):
        lab['text'] = self.color
        ent.delete(0, END)
        ent.insert(0, self.hex_color)


root = Tk()

lab = Label(width=15, height=1, justify=CENTER)
ent = Entry(width=15, justify=CENTER)
lab.pack()
ent.pack()

for i in range(7):
    ButtonRainbow(i)


# #ff0000 – red, #ff7d00 – orange, 
# #ffff00 – yellow, #00ff00 – green, 
# #007dff – blue, #0000ff – blue, #7d00ff – violet

# b1 = ButtonRainbow('red', '#ff0000')
# b2 = ButtonRainbow('orange', '#ff7d00')
# b3 = ButtonRainbow('yellow', '#ffff00')
# b4 = ButtonRainbow('green', '#00ff00')
# b5 = ButtonRainbow('Голубой', '#007dff')
# b6 = ButtonRainbow('blue', '#0000ff')
# b7 = ButtonRainbow('violet', '#7d00ff')

root.mainloop()