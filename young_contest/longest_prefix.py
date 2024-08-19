strs = ["flower","flow","flight"]


lst = sorted(strs, key=len)

prefix = ""

one = lst[0]

for i in range(len(one)):
    ch = one[i]
    for item in lst[1:]:
        if ch != item[i]:
            break
    else:
        prefix += ch

print(prefix)