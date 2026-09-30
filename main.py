from copy import deepcopy
from dataclasses import dataclass, field


@dataclass
class Author:
    first_name: str
    last_name: str
    _temp_data: list = field(default_factory=list)

    def __repr__(self):
        return f"{self.first_name, self.last_name}: id_author = {id(self)}"


@dataclass
class Book:
    title: str
    author: Author
    _cash: list = field(default_factory=list)

    def __deepcopy__(self, memo: dict = {}):
        if self in memo:
            return memo[self]

        book_cp = Book(self.title, deepcopy(self.author))
        memo[self] = book_cp
        book_cp._cash = field(default_factory=list)

        return book_cp

    def __repr__(self):
        return f"{self.title, self.author}: id = {id(self)}"


class Library:
    def __init__(self, books: list[Book] | None = None):
        self.books = books if books else []

    def __deepcopy__(self, memo: dict = {}):
        if self in memo:
            return memo[self]

        lib_cp = Library()
        memo[self] = lib_cp
        lib_cp.books = [deepcopy(deepcopy(obj), memo) for obj in self.books]

        return lib_cp

    def add_book(self, book):
        self.books.append(book)

    def show_books(self):
        for b in self.books:
            print(b)


books_list = [
    Book("Евгений Онегин", Author("Александр", "Пушкин")),
    Book("Анна Каренина", Author("Лев", "Толстой")),
    Book("Алые паруса", Author("Александр", "Грин")),
    Book("Фауст", Author("Иоганн", "Гёте")),
]

lib = Library(books_list)
lib_cpy = deepcopy(lib)
