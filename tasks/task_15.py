# O. Файлы-файлы
# import re
# s =  input()

# st = "Например, файлы abacaba123.hlm и 123.brhl интересуют его, а aAacaba123.hlm a.brhl.py и hlm.cpp нет. Также Пахома не интересуют имена, .hlm, .brhl"
# st1 = "12:21:10 12/01/2022 127.0.0.1 error abc.hlm is broken."
res = []

with open("input_15.txt") as f:
    s = f.read()


for w in s.split():
    if w.endswith('.hlm') or w.endswith('.brhl') or w.endswith('.hlm.') or w.endswith('.brhl.'):
        if w.islower() and not w.startswith('.'):
            print(w.rstrip('.'))