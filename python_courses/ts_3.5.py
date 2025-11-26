def find_number(filename: str) -> tuple[int, int]:
    count = 0
    sum_num = 0
    file = open(filename)

    for num in file:
        if len(num.strip()) == 3:
            count += 1
        elif len(num.strip()) == 2:
            sum_num += int(num.strip())

    return count, sum_num


print(find_number("numbers.txt"))