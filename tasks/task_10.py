# J. Провода и разъёмы

n, k = int(input()), int(input())
d = {}

for i in range(n):
    d[i] = set(map(int, input().split()))

devect = set(map(int, input().split()))

res = {}
for item in d.values():
    tmp_set = item - devect
    for p in tmp_set:
        res[p] = res.get(p, 0) + 1

sort_lst = sorted(res.items(), key=lambda para: para[1], reverse=True)

sort_val = sorted(val[1] for val in sort_lst[:k])
print(*sort_val, sep="\n")