from pprint import pprint


def save_board(n):
    with open("chess_board.txt", "w", encoding="utf-8") as f:
        for i in range(n):
            line = ""
            for j in range(n):
                if (i + j) % 2 == 0:
                    line += "#"
                else:
                    line += "."
            line += "\n"
            f.write(line)


def create_file_with_numbers(n):
    with open(f"range_{n}.txt", "w", encoding="utf-8") as f:
        for i in range(1, n + 1):
            f.write(str(i) + "\n")


def export_poll_results(results: dict):
    with open("results.txt", "w", encoding="utf-8") as f:
        sorted_dict = dict(sorted(results.items(), key=lambda item: item[1], reverse=True))
        f.write("Результаты опроса:\n")
        for i, key in enumerate(sorted_dict, 1):
            line = f"{i}. {key} — {sorted_dict[key]} голосов\n"
            f.write(line)


d = {"Python": 38, "JavaScript": 25, "C++": 12, "Java": 17}


def export_poll_results(*args):
    res = {}
    for item in args:
        for key in item:
            if key not in res:
                res[key] = item[key]
            else:
                res[key] += item[key]
    sorted_list = sorted(res.items(), key=lambda item: item[1], reverse=True)
    res = {}
    for item in sorted_list:
        if item[1] not in res:
            res[item[1]] = item[0]
        else:
            res[item[1]] += "," + item[0]
    with open("results.txt", "w", encoding="utf-8") as f:
        f.write("Итоги общего голосования:\n")
        for i, key in enumerate(res, 1):
            s = sorted(res[key].split(","))
            line = f"{i}. {", ".join(s)} — {key} голосов\n"
            f.write(line)


def generate_receipt(purchases: list[dict]):
    with open("receipt.txt", "w", encoding="utf-8") as f:
        f.write("==== Чек покупок ====\n")
        total = 0
        for i, item in enumerate(purchases, 1):
            name = item.get("название")
            price = item.get("цена")
            quantity = item.get("количество")
            tmp = price * quantity
            f.write(f"{i}. {name} ({quantity:.2f} × {price:.2f}) = {tmp:.2f}\n")
            total += tmp
        end = f"---------------------\nИТОГО: {total:.2f} руб\n======================"
        f.write(end)


# purchases = [
#     {"название": "Яблоко", "цена": 30.5, "количество": 3},
#     {"название": "Хлеб", "цена": 45.1, "количество": 1.5},
#     {"название": "Молоко", "цена": 60.44, "количество": 2},
# ]
purchases = [
    {"название": "Шоколад", "цена": 99.99, "количество": 2},
    {"название": "Сок", "цена": 50.5, "количество": 1.2},
]


def map_coordinates(coords):
    return [(int(coord[1:]) - 1, ord(coord[0]) - ord("A")) for coord in coords]


def mark_hits(field_file, shots_file):
    with open(
        field_file,
        encoding="utf-8",
    ) as f1, open(
        shots_file,
        encoding="utf-8",
    ) as f2, open(
        "updated_field.txt",
        "w",
        encoding="utf-8",
    ) as f3:
        fields = list(line.strip().split() for line in f1.readlines())
        shots = map_coordinates(list(line.strip() for line in f2.readlines()))

        for i in range(len(fields)):
            for j in range(len(fields)):
                if (i, j) in shots:
                    if fields[i][j] == "■":
                        fields[i][j] = "X"
                    else:
                        fields[i][j] = "•"
        for s in fields:
            line = " ".join(s)
            f3.write(line + "\n")


mark_hits("field.txt", "shots.txt")
