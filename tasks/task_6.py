# F. Новый роутер

x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
x3 = int(input())
y3 = int(input())

def new_router(x1, y1, x2, y2, x3, y3):    
    if x1 <= x3 <= x2 and y1 <= y3 <= y2:
        return False
    d_ax = x3 - x1
    d_ay = y3 - y1
    a_new_x = x3 + d_ax
    a_new_y = y3 + d_ay
    d_bx = x3 - x2
    d_by = y3 - y2
    b_new_x = x3 + d_bx
    b_new_y = y3 + d_by
    return a_new_x, a_new_y, b_new_x, b_new_y

res = new_router(x1, y1, x2, y2, x3, y3)

if not res:
    print(res)
else:
    for item in res:
        print(item)
