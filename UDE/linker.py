from ctypes import CDLL
import subprocess
import os

# gcc -shared -fPIC -o ./PyWin32/cpy/module.so ./PyWin32/Win32.c

with open( os.path.dirname(__file__) + "/lib/linked.c", "w") as NFile:
    for file in os.listdir( os.path.dirname(__file__) + "/C_src"):
        if os.path.isfile( os.path.dirname(__file__) + "/C_src/" + file):
            with open   ( os.path.dirname(__file__) + "/C_src/" + file, "r") as CFile:
                NFile.write( CFile.read() + "\n" )

subprocess.call(['gcc', '-shared', '-fPIC', '-o', os.path.dirname(__file__) + '/lib/linked.so', os.path.dirname(__file__) + '/lib/linked.c'])
C = CDLL(os.path.dirname(__file__) + '/lib/linked.so')