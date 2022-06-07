import UDE

win = UDE.Window(300, 300)
text = UDE.Label(x=100, y=50, width=100, height=50)
submit = UDE.Button(x=100, y=150, width=100, height=50)

win.init(b"window")
text.render(win, b"Text")
submit.render(win, b"Test")

while True:
    UDE.update(win)

    if submit.clicked():
        UDE.set_label_text(text, "Hello World!".encode())

    UDE.time.sleep(round(1000/60))
