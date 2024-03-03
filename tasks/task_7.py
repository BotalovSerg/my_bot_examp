a, b = int(input()), int(input())
cnt = 0
buff = ''
while True:
    s = input().strip()
    if s == '0':
        print(buff.strip())
        break
    if len(buff + s) > a or cnt >= b:
        print(buff.strip())
        cnt = 1
        buff = s + " "
    else:
        buff += s + " "
        cnt += 1