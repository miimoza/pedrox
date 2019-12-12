#!/usr/bin/python3

import os
from syllables import syllables

class color:
    DEFAULT = "\033[39m"
    GREEN = "\033[92m"
    RED = "\033[91m"

recorded = [os.path.splitext(f)[0].upper() for f in os.listdir("soundbank")]

for i in range(len(syllables)):
    if (i % 8 == 0):
        print()
    s = syllables[i]
    if bool(set(s) & set(recorded)):
        print(color.GREEN, end="");
    else:
        print(color.RED, end="")
    print(s[0].rjust(5), end=color.DEFAULT + " ")

print()
