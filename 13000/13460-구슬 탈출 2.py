import math

if __name__ == '__main__':
    N = int(input())
    for i in range(N):
        x1,y1,r1,x2,y2,r2 = map(int,input().split())
        d = math.sqrt((x1-x2)**2+(y1-y2)**2)
        if d == r1+r2:
            print(1)
        elif d > r1+r2:
            print(0)
        elif d == 0:
            if r1 != r2:
                print(0)
            else:
                print(-1)
        else:
            print(2)