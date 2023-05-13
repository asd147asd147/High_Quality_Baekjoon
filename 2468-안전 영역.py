import sys
from queue import Queue

N = (int)(sys.stdin.readline())

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

region = []
height = set()
for _ in range(N):
    line = list(map(int,(sys.stdin.readline().rstrip().split())))
    height.update(line)
    region.append(line)

ans = 1

for h in height:
    for i in range(N):
        for j in range(N):
            if region[i][j] == h:
                region[i][j] = 0

    visited = [[False for _ in range(N)] for _ in range(N)]
    q = Queue()
    cnt = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False and region[i][j] != 0:
                q.put((i,j))
                visited[i][j] = True
                cnt += 1
                while q.qsize() > 0:
                    p = q.get()
                    for d in range(4):
                        y, x = p[0]+dy[d], p[1]+dx[d]
                        if 0 <= y < N and 0 <= x < N and visited[y][x] == False and region[y][x] != 0:
                            q.put((y, x))
                            visited[y][x] = True
    ans = max(ans, cnt)

sys.stdout.write((str)(ans))