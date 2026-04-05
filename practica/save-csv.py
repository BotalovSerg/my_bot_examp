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


print_column_values("library_books.csv", "Автор")
