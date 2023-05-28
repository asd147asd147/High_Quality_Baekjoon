import sys
import math
sys.setrecursionlimit(10**5)

input = sys.stdin.readline

N = int(input())

depth = [0] * (N+1)
ac = [[0]*18 for _ in range(N+1)]
min_road = [[sys.maxsize]*18 for _ in range(N+1)]
max_road = [[0]*18 for _ in range(N+1)]
adj = [[] for _ in range(N+1)]

def getTree(here, parent, road_len):
    depth[here] = depth[parent]+1

    ac[here][0] = parent
    min_road[here][0] = max_road[here][0] = road_len

    max_level = int(math.log2(N+1))

    for i in range(1,max_level+1):
        if ac[here][i-1]:
            ac[here][i] = ac[ac[here][i-1]][i-1]
            min_road[here][i] = min(min_road[ac[here][i-1]][i-1], min_road[here][i-1])
            max_road[here][i] = max(max_road[ac[here][i-1]][i-1], max_road[here][i-1])

    for there, road in adj[here]:
        if there != parent:
            getTree(there, here, road)

for _ in range(N-1):
    A, B, C = map(int,input().split())
    adj[A].append((B,C))
    adj[B].append((A,C))

depth[0] = -1
getTree(1,0,0)

def findMinMaxRoad(a,b):
    minimum, maximum = sys.maxsize, 0
    if depth[a] != depth[b]:
        if depth[a] < depth[b]:
            a, b = b, a
    diff = depth[a] - depth[b]
    i = 0
    while True:
        if diff % 2:
            minimum = min(minimum, min_road[a][i])
            maximum = max(maximum, max_road[a][i])
            a = ac[a][i]
        i+=1
        diff >>= 1
        if not diff > 0: break
    
    if a != b:
        for k in range(17,-1,-1):
            if ac[a][k] != 0 and ac[a][k] != ac[b][k]:
                minimum = min(minimum, min_road[a][k], min_road[b][k])
                maximum = max(maximum, max_road[a][k], max_road[b][k])
                a = ac[a][k]
                b = ac[b][k]
        minimum = min(minimum, min_road[a][0], min_road[b][0])
        maximum = max(maximum, max_road[a][0], max_road[b][0])

    return minimum, maximum

K = int(input())
for _ in range(K):
    a, b = map(int, input().split())
    minimum, maximum = findMinMaxRoad(a,b)
    sys.stdout.write(str(minimum)+" "+str(maximum)+"\n")