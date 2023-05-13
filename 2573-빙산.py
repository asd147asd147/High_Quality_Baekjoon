import sys
from collections import deque

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N, M = map(int, sys.stdin.readline().split())

iceberg = [ list(map(int,sys.stdin.readline().split())) for _ in range(N) ]
ans = 0
year = 0

iceberg_pos = []
for i in range(N):
        for j in range(M):
            if iceberg[i][j] != 0:
                iceberg_pos.append((i,j))

while iceberg_pos:
    visited = [[False] * M for _ in range(N)]

    q = deque()
    cnt = 0
    delList = []
    for i, j in iceberg_pos:
        seaList = []
        if iceberg[i][j] == 0: delList.append((i,j))
        elif visited[i][j] == False:
            q.append((i,j))
            cnt += 1
            if cnt > 1: break

            visited[i][j] = True
            while len(q):
                p = q.popleft()
                sea = 0
                for dxs, dys in zip(dx, dy):
                    ys, xs = p[0] + dys, p[1] + dxs
                    if 0 <= xs < M and 0 <= ys < N:
                        if iceberg[ys][xs] == 0:
                            sea+=1
                        elif visited[ys][xs] == False:
                            q.append((ys,xs))
                            visited[ys][xs] = True

                if sea > 0:
                    seaList.append((p[0], p[1], sea))
    
            for y, x, sea in seaList:
                iceberg[y][x] = max(0, iceberg[y][x] - sea)

    if cnt == 0:
        ans = 0
        break
    elif cnt > 1:
        ans = year
        break

    iceberg_pos = list(set(iceberg_pos) - set(delList))
    year += 1

sys.stdout.write((str)(ans))