"""
Известная компания Тындекс в очередной раз проводит набор стажёров.
Заботясь о персональных данных соискателей, компания придумала хитрый алгоритм шифрования:

Подсчитывается количество различных символов в ФИО (регистр важен, А и а — разные символы).
Берётся сумма цифр в дне и месяце рождения, умноженная на
6
4
.
Для первой (по позиции в слове) буквы фамилии определяется её номер в алфавите (в
1
-индексации), умноженный на
2
5
6
 (регистр буквы не важен).
Полученные числа суммируются.
Результат переводится в
1
6
-чную систему счисления (в верхнем регистре).
У результата сохраняются только
3
 младших разряда (если значимых разрядов меньше, то шифр дополняется до
3
-х разрядов ведущими нулями).
Ваша задача — помочь вычислить для каждого кандидата его шифр.

Ввод:
2
Volozh,Arcady,Yurievich,11,2,1964
Segalovich,Ilya,Valentinovich,13,9,1964

"""
from string import ascii_lowercase


def sum_day_mouth(list_bd):
    res = 0
    for num in list_bd:
        for i in num:
            res += int(i)

    return res



def encode_candidate(data: str):

    tmp = data.split(",")
    s = len(set(tmp[0]+tmp[1]+tmp[2]))
    sum_bd = sum_day_mouth(tmp[3:5])
    first_s_idx = ascii_lowercase.find(tmp[0][0].lower()) + 1
    total = s + sum_bd*64 + first_s_idx*256

    return f"{total:X}"[-3:]



def main():
    n = int(input())
    list_candidates = [input() for _ in range(n)]

    for item in list_candidates:
        print(encode_candidate(item), end=" ")


if __name__ == "__main__":
    main()