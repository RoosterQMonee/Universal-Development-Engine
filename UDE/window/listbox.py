from .widget import Widget
from ..linker import C


class ListBox:
    def __init__(self, x=0, y=0, width=10, height=10):
        self.data = Widget(width, height)
        self.position = [x, y]
        self.obj = None

    def render(self, parent):
        self.obj = C.new_listbox(parent.window, self.position[0], self.position[1], self.data.width, self.data.height)

    def add_item(self, item):
        C.add_to_listbox(self.parent, item)