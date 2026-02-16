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
