from collections import OrderedDict

row_data = [_row.split('=') for _row in input().split()]

data = OrderedDict(row_data)

data.popitem(last=False)
find_key = "people" in data

print(*data.values())
