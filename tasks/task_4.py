
def main():
    n = int(input())
    s = 0
    lst = [[0] * 3 for i in range(20)]
    lst[0][0]=lst[0][1]=lst[0][2]=1
    for i in range(1, n):
        lst[i][0]=lst[i-1][1]+lst[i-1][2]
        lst[i][2]=lst[i][1]=lst[i-1][0]+lst[i-1][1]+lst[i-1][2]
    for i in range(3):
        s += lst[n-1][i]
    
    print(s)

if __name__=='__main__':
    main()

