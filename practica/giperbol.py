import time

a = 1
result = 0
while True:
    a /= 2
    print("a-> ", a)
    result += a
    print("result-> ", result)
    time.sleep(2)
