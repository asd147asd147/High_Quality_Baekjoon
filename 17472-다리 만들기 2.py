from collections import deque
import heapq
import sys

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def find_island(board, visited, i, j, num):
    q = deque([])
    q.append((i,j))
    visited[i][j] = True

    island_pos = []
    while len(q):
        i, j = q.popleft()
        board[i][j] = num
        island_pos.append((i,j))
        for k in range(4):
            y, x = i+dy[k], j+dx[k]
            if 0 <= y < N and 0 <= x < M and board[y][x] and not visited[y][x]:
                q.append((y,x))
                visited[y][x] = True
    return island_pos


input = sys.stdin.readline

N, M = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]

visited = [[False] * M for _ in range(N)]

islands = []
num = 1
for i in range(N):
    for j in range(M):
        if board[i][j] and not visited[i][j]:
            islands.append(find_island(board, visited, i, j, num))
            num += 1

adj = [[] for _ in range(num)]

for n, island in enumerate(islands, start=1):
    for i, j in island:
        for k in range(4):
            y, x = i+dy[k], j+dx[k]
            dist = 1
            if 0 <= y < N and 0 <= x < M and board[y][x] == 0:
                while True:
                    y, x = y+dy[k], x+dx[k]
                    if not (0 <= y < N and 0 <= x < M):
                        break
                    if board[y][x] == n:
                        break
                    if board[y][x] != 0 and board[y][x] != n:
                        if dist < 2: break
                        else:
                            adj[n].append((board[y][x], dist))
                            break
                    dist+=1

s = set()
for i, a in enumerate(adj):
    for n, dist in a:
        s.add((dist, min(i,n), max(i,n)))
pq = list(s)
heapq.heapify(pq)

parent = [i for i in range(num)]

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
        return parent[x]
    return x

def union(x, y):
    x = find_parent(x)
    y = find_parent(y)
    parent[y] = x


ans = 0
while len(pq):
    dist, i, j = heapq.heappop(pq)
    if find_parent(i) == find_parent(j): continue
    else:
        union(i, j)
        ans += dist

for i in range(1, num):
    if find_parent(1) != find_parent(i):
        ans = -1
sys.stdout.write(str(ans))