from .window.checkbox import CheckBox
from .window.combobox import ComboBox
from .window.listbox import ListBox
from .window.textbox import TextBox
from .window.widget import Widget
from .window.button import Button
from .window.update import update
from .window.label import Label
from .linker import C

class Window(Widget):
    def __init__(self, width=100, height=100):
        self.data = Widget(width, height)
        self.window = None

    def init(self, title):
        self.window = C.create_window(title, self.data.width, self.data.height)

    def update(self):
        self.window.update()
