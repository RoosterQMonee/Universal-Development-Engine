from ..linker import C

ticks = 0

class time:
    def sleep(milliseconds):
        C.sleep(milliseconds)

    def utc():
        return C.utc()

    def date():
        return C.date()

    def fps(fps):
        return C.fps(fps)

    def tick():
        global ticks
        ticks += 1

        return ticks

    def get_ticks():
        return ticks