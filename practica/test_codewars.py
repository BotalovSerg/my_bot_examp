def multi(num):
    res = 1
    while num > 0:
        res *= num%10
        num //= 10
    return res


def dig_pow(n, p):
    res = n
    n = int(str(n)[::-1])
    tmp = 0
    while n > 0:
        tmp += (n%10)**p
        n //= 10
        p += 1
    if tmp % res == 0:
        return tmp // res
    return -1


def find_next_square(sq):
    sqr_num = sq ** 0.5
    
    return (sqr_num+1)**2 if sq%sqr_num == 0 else -1

print(find_next_square(121))
print(find_next_square(625))
print(find_next_square(114))