#!/usr/bin/python3

import os
from syllables import syllables

os.system("rm -rf ./generated")
os.system("mkdir generated")

recorded_files = os.listdir("soundbank")
recorded = [os.path.splitext(f)[0].upper() for f in os.listdir("soundbank")]

for i in range(len(recorded)):
    s = []
    for j in range(len(syllables)):
        if recorded[i] in syllables[j]:
            s = syllables[j]
    for j in s:
        os.system("cp ./soundbank/" + recorded_files[i] + " ./generated/" + j + ".wav")
