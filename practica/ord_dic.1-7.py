from collections import OrderedDict, defaultdict

# row_data = [(_row.split("=")[0], tuple(map(int, _row.split("=")[1].split("-")))) for _row in input().split()]


# st_marks = OrderedDict(row_data)


# for key, val in st_marks.items():
#     marks = defaultdict(int)
#     for v in val:
#         marks[v] += 1

#     st_marks[key] = marks


d1 = dict(a=1, b=2, c=3)
d2 = OrderedDict(b=2, a=1, c=3)
d3 = OrderedDict(a=1, b=2, c=3)

print(d1 == d2)
print(d1 == d3)
print(d3 == d2)
print(d1 < d2)