def odd_numbers_generator():
    current = 10
    # Убедимся, что начинаем с первого нечетного числа после 10
    if current % 2 == 0:
        current += 1
    while True:
        yield current
        current += 2


# Пример использования:
gen = odd_numbers_generator()

# Выведем первые 5 нечетных чисел, начиная с 11
for _ in range(5):
    print(next(gen))


def odd_numbers(start=10):
    # если start четный — начинаем с следующего нечетного
    n = start if start % 2 == 1 else start + 1
    while True:
        yield n
        n += 2


# Пример использования: выведем первые 5 значений
g = odd_numbers(10)
for _ in range(5):
    print(next(g))  # 11, 13, 15, 17, 19


# Альтернатива с itertools
from itertools import count, islice

odds = count(11, 2)  # 11, 13, 15, ...

print(list(islice(odds, 5)))  # [11, 13, 15, 17, 19]
