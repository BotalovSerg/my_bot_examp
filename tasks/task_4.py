# N, M, x, y = int(input()),int(input()),int(input()),int(input())

# M_y = M - y
# N_x = N - x

# print(min(x, y, M_y, N_x))

def main():
    N, M, x, y = int(input()),int(input()),int(input()),int(input())
    N, M = min(N, M), max(N, M)
    if x == 0 or y == 0:
        return 0
    M_y = M - y
    N_x = N - x
    return min(x, y, M_y, N_x)

if __name__ == '__main__':
    print(main())