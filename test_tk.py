from tkinter import * 


tk = Tk()

tk.title("Exemple work kb")
tk.geometry("300x150")

info = StringVar()
info_str = "Press key with cod: "

def keypress(event):
    info.set(info_str + str(event.keycode))

label = Label(tk, textvariable=info, font=("Arial", "20"))
info.set("Press on key")
label.pack()
tk.bind('<Key>', keypress)
tk.mainloop()