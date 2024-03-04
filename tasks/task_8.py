# H. Повторяющиеся подстроки

s = input()
N = int(input())

d = {}
for i in range(len(s)):
    key = s[i:N + i]
    if len(key) != N:
        break
    d[key] = d.get(key, 0) + 1
res = []
for key, val in d.items():
    if val > 1:
        res.append(key)

print(sorted(res))