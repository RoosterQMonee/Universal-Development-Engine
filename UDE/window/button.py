from .widget import Widget
from ..linker import C

class Button:
    def __init__(self, x=0, y=0, width=10, height=10):
        self.data = Widget(width, height)
        self.position = [x, y]
        self.obj = None

    def render(self, parent, text):
        self.obj = C.new_button(parent.window, text, self.position[0], self.position[1], self.data.width, self.data.height)

    def clicked(self):
        return C.get_button_state(self.obj) == 620

    def hovering(self):
        return C.get_button_state(self.obj) == 520

    def rendered(self):
        return C.get_button_state(self.obj) == 8