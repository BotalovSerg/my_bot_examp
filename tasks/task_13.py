# M. Contains Duplicate Symbols

s = input()

for i in s:
    if s.count(i) > 1:
        print(True)
        break
else:
    print(False)