# K. Пахом и орфография

a, b = int(input()), int(input())

item = ["*   * ", "*  ** ", "* * * " , "**  * ", "*   * "]
for i in range(a):
    for s in item:
        print(s * b)
    print()