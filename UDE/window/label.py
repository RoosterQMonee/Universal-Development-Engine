from .widget import Widget
from ..linker import C


class Label:
    def __init__(self, x=0, y=0, width=10, height=10):
        self.data = Widget(width, height)
        self.position = [x, y]
        self.obj = None

    def render(self, parent, text):
        self.obj = C.new_label(parent.window, text, self.position[0], self.position[1], self.data.width, self.data.height)