import UDE

win = UDE.Window(300, 300)
button = UDE.Button(x=120, y=100, width=50, height=50)

win.init(b"window")
button.render(win, b"Box.")

while True:
    UDE.update(win)
    UDE.time.sleep(round(1000/60))
    #print(f"Clicked: {button.clicked()} | Hovering: {button.hovering()} | Rendered: {button.rendered()}")

    if button.clicked():
        print("Box.")