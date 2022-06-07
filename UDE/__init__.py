from .linker import *
from .lib.moddata import *
from .window_handle import *
from .c_handle import *
import os

with open(os.path.dirname(__file__)+"/files.py", "w") as imports:
    for file in os.listdir(os.path.dirname(__file__)):
        if file.endswith(".py") and file != "__init__.py" and file != "files.py" and os.path.isfile(file):
            imports.write(f"from .{file[:-3]} import *\n")

try:
    from .files import *

    print("Loaded UDE: ", os.path.dirname(__file__))
    print("UDE version: ", UDE_VERSION)
    print("UDE author: ", UDE_AUTHOR)

except ImportError:
    print("UDE: Could not import main modules.")

except Exception as e:
    print(f"UDE: {e}")