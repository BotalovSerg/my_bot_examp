# A. Остаток на C++

a, b = map(int, input().split())

if a < 0:
    print(-(abs(a)%b))
else:
    print(a % b)