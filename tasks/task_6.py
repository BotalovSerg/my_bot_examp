# F. Новый роутер

x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
x3 = int(input())
y3 = int(input())

def new_router(x1, y1, x2, y2, x3, y3):
    min_x, max_x = min(x1, x2), max(x1, x2)    
    min_y, max_y = min(y1, y2), max(y1, y2)    
    if min_x <= x3 <= max_x and min_y <= y3 <= max_y:
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
