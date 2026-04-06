import csv


def print_book_titles(fname):
    with open(fname, encoding="utf-8") as f:
        it = csv.reader(f)
        next(it)
        for row in it:
            print(row[1])


def print_column_values(filename: str, column_name: str) -> None:
    with open(filename, encoding="utf-8") as f:
        it = csv.reader(f)
        col = next(it)
        try:
            inx_col = col.index(column_name)
        except ValueError:
            print(f'Колонка "{column_name}" не найдена.')
            return
        for row in it:
            print(row[inx_col])


# print_column_values("library_books.csv", "Автор")


def print_columns(filename: str, columns: list[str]) -> None:
    with open(filename, encoding="utf-8") as f:
        it = csv.reader(f)
        header = next(it)
        list_indexs = []
        for col in columns:
            if col in header:
                list_indexs.append(header.index(col))
            else:
                list_indexs.append("N/A")

        if list_indexs.count("N/A") == len(list_indexs):
            print("Указанные колонки не найдены.")
            return

        for row in it:
            for i, val in enumerate(list_indexs):
                if val == "N/A":
                    print("N/A", end=f"{';' if i < len(list_indexs) - 1 else '\n'}")
                else:
                    print(row[val], end=f"{';' if i < len(list_indexs) - 1 else '\n'}")


print_columns("library_books.csv", ["Автор", "Рейтинг"])
