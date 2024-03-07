# L. Очень сложный парол


i = int(input())
cnt = 0
num  = 332
while i != cnt:
    num += 1
    while True:
        if str(num).count("3") == 3:
            cnt += 1
            break
        num += 1
print(num)