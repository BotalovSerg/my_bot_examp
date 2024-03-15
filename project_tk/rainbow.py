from tkinter import *




class ButtonRainbow:
    def __init__(self, color, hex_color) -> None:
        self.btn = Button()
        self.btn.config(bg=hex_color, command=self.clik, width=15)
        self.color = color
        self.hex_color = hex_color
        self.btn.pack()

    def clik(self):
        lab_1['text'] = self.color
        lab_2['text'] = self.hex_color


root = Tk()

lab_1 = Label(width=10, height=1, justify=CENTER)
lab_2 = Label(width=10, height=1)
lab_1.pack()
lab_2.pack()

# #ff0000 – red, #ff7d00 – orange, 
# #ffff00 – yellow, #00ff00 – green, 
# #007dff – blue, #0000ff – blue, #7d00ff – violet

b1 = ButtonRainbow('red', '#ff0000')
b2 = ButtonRainbow('orange', '#ff7d00')
b3 = ButtonRainbow('yellow', '#ffff00')
b4 = ButtonRainbow('green', '#00ff00')
b5 = ButtonRainbow('Голубой', '#007dff')
b6 = ButtonRainbow('blue', '#0000ff')
b7 = ButtonRainbow('violet', '#7d00ff')

root.mainloop()