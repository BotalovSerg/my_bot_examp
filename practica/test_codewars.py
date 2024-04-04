def multi(num):
    res = 1
    while num > 0:
        res *= num%10
        num //= 10
    return res


def persistence(n):
    cnt = 0
    if 0 < n < 10:
        return cnt
    while n >= 10:
        cnt += 1
        n = multi(n)
    return cnt
print(persistence(4))
print(persistence(39))
print(persistence(25))
print(persistence(999))
