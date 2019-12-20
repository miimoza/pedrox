#!/usr/bin/python3

import os
from syllables import syllables

os.system("rm -rf ./generated")
os.system("mkdir generated")

recorded_files = os.listdir("soundbank")
recorded = [os.path.splitext(f)[0].upper() for f in os.listdir("soundbank")]


# UPDATE GENERATED SOUND BANK
for i in range(len(recorded)):
    s = []
    for j in range(len(syllables)):
        if recorded[i] in syllables[j]:
            s = syllables[j]
    for j in s:
        os.system("cp ./soundbank/" + recorded_files[i] + " ./generated/" + j + ".wav")


# GENERATE FR_SYLLABLES.H
recorded.sort(key = lambda s: len(s), reverse=True)
filename = "../../voice/src/fr_syllables.h"
if os.path.exists(filename):
    os.remove(filename)
header_file = open(filename, "a")
header_file.write("#ifndef FR_SYLLABLES_H\n#define FR_SYLLABLES_H\n\n")
header_file.write("#define FR_SYLLABLES_LEN = " + str(len(recorded)) + ";\n\n")
header_file.write("char const **FR_SYLLABLES = {\n\t")
for i in range(len(recorded) - 1):
	if (i+1) % 8 == 0:
		header_file.write("\"" + recorded[i] + "\",\n\t")
	else:
		header_file.write("\"" + recorded[i] + "\", ")
header_file.write("\"" + recorded[-1] + "\"\n}\n\n")
header_file.write("#endif /* FR_SYLLABLES_H */")
header_file.close()
