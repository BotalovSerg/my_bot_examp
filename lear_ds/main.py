a = 0.1
x = 3
step = 1
while step <= 50:
    tmp = x - a * 2 * x
    print(f"step {step}, res {tmp}")
    x = tmp
    step += 1
