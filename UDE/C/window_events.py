from ..linker import C

def check_button(win):
    return C.get_button_state(win.obj)

def close_window(win):
    C.close_window(win.window)

def messagebox(message, title):
    C.message_box(message, title)

def set_label_text(win, text):
    C.set_label_text(win.obj, text)

def set_textbox_text(win, text):
    C.set_textbox_text(win.obj, text)

def set_button_text(win, text):
    C.set_button_text(win.obj, text)

def get_textbox_text(win):
    return C.get_textbox_text(win.obj)
