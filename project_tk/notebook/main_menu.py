from tkinter import Menu, Tk
from text_editor import TextEditor


theme_colors = {
    'dark': {
        'text_bg': 'black', 'text_fg': 'lime', 'cursor': 'brown', 'select_bg' : '#8D917A'
    },
    'light': {
        'text_bg': 'white', 'text_fg': 'black', 'cursor': '#A5A5A5', 'select_bg' : '#FAEEDD'
    },
}


class MainMenu:
    def __init__(self, master: Tk, text_editor: TextEditor) -> None:
        self.menu = Menu(master)
        self.text_editor = text_editor
        self.create_file_menu(master)
        self.create_view_menu(master)
        self.menu.add_cascade(label='File', menu=self.file_menu)
        self.menu.add_cascade(label='View', menu=self.view)
        master.config(menu=self.menu)

    def create_file_menu(self, master: Tk):
        self.file_menu = Menu(self.menu, tearoff=0)
        self.file_menu.add_command(label='Open')
        self.file_menu.add_command(label='Save')
        self.file_menu.add_separator()
        self.file_menu.add_command(label='Close')
        master.config(menu=self.file_menu)

    def create_view_menu(self, master: Tk):
        self.view = Menu(self.menu, tearoff=0)
        self.view_color = Menu(self.view, tearoff=0)
        self.view_color.add_command(label='Dark', command=lambda: self.change_theme('dark'))
        self.view_color.add_command(label='Light', command=lambda: self.change_theme('light'))
        self.view.add_cascade(label='Theme', menu=self.view_color)

        self.view_font = Menu(self.view, tearoff=0)
        self.view_font.add_command(label='Arial')
        self.view_font.add_command(label='Comic Sans MS')
        self.view_font.add_command(label='Times New Roman')
        self.view.add_cascade(label='Font', menu=self.view_font)
        master.config(menu=self.view)

    def change_theme(self, color):
        self.text_editor.text['bg'] = theme_colors[color]['text_bg']
        self.text_editor.text['fg'] = theme_colors[color]['text_fg']
        self.text_editor.text['insertbackground'] = theme_colors[color]['cursor']
        self.text_editor.text['selectbackground'] = theme_colors[color]['select_bg']