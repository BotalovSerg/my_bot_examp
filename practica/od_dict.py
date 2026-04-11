from collections import OrderedDict

# row_data = [_row.split("=") for _row in input().split()]

# data = OrderedDict(row_data)

# data.popitem(last=False)
# find_key = "people" in data

# print(*data.values())

# od_fifo = OrderedDict(row_data)

# od_sum = sum(int(n) for n in od_fifo.values())
# print(od_fifo.popitem()[0], od_fifo.popitem()[0], od_fifo.popitem()[0])


morze_dict = {
    "а": ".-",
    "б": "-...",
    "в": ".--",
    "г": "--.",
    "д": "-..",
    "е": ".",
    "ё": ".",
    "ж": "...-",
    "з": "--..",
    "и": "..",
    "й": ".---",
    "к": "-.-",
    "л": ".-..",
    "м": "--",
    "н": "-.",
    "о": "---",
    "п": ".--.",
    "р": ".-.",
    "с": "...",
    "т": "-",
    "у": "..-",
    "ф": "..-.",
    "х": "....",
    "ц": "-.-.",
    "ч": "---.",
    "ш": "----",
    "щ": "--.-",
    "ъ": "--.--",
    "ы": "-.--",
    "ь": "-..-",
    "э": "..-..",
    "ю": "..--",
    "я": ".-.-",
    " ": "-...-",
}

morze = OrderedDict(morze_dict)

s = input()
r = []
for c in s:
    r.append(morze[c.lower()])

print(*r)

morze_dec = OrderedDict(((v, k) for k, v in morze.items()))
print(morze_dec)
