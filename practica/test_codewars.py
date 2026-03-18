from enum import Enum


class TypeBook(Enum):
    DRAMA = 3
    THRILLER = "thriller"
    LOVESTORY = (0, 1, 2)

    @classmethod
    def get_default(cls):
        return cls.LOVESTORY


p_th = TypeBook.THRILLER

print(p_th.name, p_th.value)


class TypeDigit(Enum):
    INT = 1
    REAL = 2
    COMPLEX = 3


def factory_digit(*args, t: TypeDigit = TypeDigit.REAL):
    if t == TypeDigit.INT:
        return int(args[0])
    if t == TypeDigit.REAL:
        return float(args[0])
    if t == TypeDigit.COMPLEX:
        return complex(args[0], args[1])


cmp = factory_digit(4.3, 2.1, t=TypeDigit.COMPLEX)
print(cmp)


class StyleWindow(Enum):
    CAPTION = 1
    DIALOG = 2
    BORDER = 4


class WindowStyle(Enum):
    CAPTION = 1
    DIALOG = 2
    BORDER = 4


p1 = StyleWindow.DIALOG
p2 = WindowStyle.DIALOG


print(p1 == p2)
print(p1.name != p2.name)
# print(p1 <= p2)
print(p1.value == p2.value)
print(p1 == 2)