import UDE

win = UDE.Window(300, 200)
answer = UDE.CheckBox(50, 50, 100, 50)
submit = UDE.Button(50, 100, 100, 50)

win.init(b"Check Test")
answer.render(win, b"Answer")
submit.render(win, b"Submit")

cooldown = 0

while True:
    UDE.update(win)

    if submit.clicked():
        if UDE.time.get_ticks() >= cooldown or cooldown == 0:
            print(answer.checked())
            cooldown = UDE.time.get_ticks() + 40

    UDE.time.tick()
    UDE.time.sleep(round(1000/60))