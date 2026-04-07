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


# print_columns("library_books.csv", ["Автор", "Рейтинг"])


def print_movies(filename: str):
    with open(filename, encoding="utf-8") as f:
        it = csv.reader(f)
        header = next(it)

        for row in it:
            title, genre, duration, rating = row
            print(f"Фильм: {title} | Жанр: {genre} | Длительность: {duration} мин | Рейтинг: {rating}")


def save_matrix_to_csv(matrix: list[list], filename: str):
    with open(filename, "w", encoding="utf-8") as f:
        wr = csv.writer(f)
        wr.writerows(matrix)


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

file_name = "matrix.csv"

# save_matrix_to_csv(matrix, file_name)


def merge_catalogs(products_filename, prices_filename):

    with open(products_filename, encoding="utf-8") as f1, open(prices_filename, encoding="utf-8") as f2:
        it1 = csv.reader(f1)
        it2 = csv.reader(f2)
        next(it1)
        next(it2)
        products = sorted(list(it1), key=lambda item: item[0])
        prices = sorted(list(it2), key=lambda item: item[0])
        prod = {item[0]: item[1] for item in products}
    result = [[item[0], prod[item[0]], item[1]] for item in prices if item[0] in prod]
    with open("merged.csv", "w", encoding="utf-8") as f:
        wr = csv.writer(f)
        wr.writerow(["id", "product", "price"])
        wr.writerows(result)


# merge_catalogs("products.csv", "prices.csv")
