import sys
from queue import Queue

F, S, G, U, D = map(int,sys.stdin.readline().split())

visited = [False for _ in range(F+1)]
visited[0] = True

q = Queue()
q.put((S, 0))
ans = -1

while q.qsize():
    p = q.get()
    visited[p[0]] = True
    if p[0] == G:
        ans = p[1]
        break
    
    if p[0]-D > 0 and not visited[p[0]-D]:
        q.put((p[0]-D, p[1]+1))
        visited[p[0]-D] = True
    if p[0]+U <= F and not visited[p[0]+U]:
        q.put((p[0]+U, p[1]+1))
        visited[p[0]+U] = True


if ans == -1:
    sys.stdout.write('use the stairs')
else:
    sys.stdout.write((str)(ans))