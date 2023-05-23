import sys
from itertools import combinations
from queue import Queue

def check_group(group):
    q = Queue()
    group = list(group)
    visited = {group[0]}
    q.put(group[0])
    while q.qsize():
        p = q.get()
        for neighbor in adj[p]:
            if neighbor in group and neighbor not in visited:
                visited.add(neighbor)
                q.put(neighbor)
    return visited


input = sys.stdin.readline

N = int(input())
people = list(map(int, input().split()))

adj = [[] for _ in range(N)]

for i in range(N):
    neighbors = list(map(int, input().split()))[1:]
    for neighbor in neighbors:
        adj[i].append(neighbor-1)
        adj[neighbor-1].append(i)

ans = 1001
for c in range(1, N//2 + 1):
    for combination in combinations(list(range(N)), c):
        A = set(combination)
        B = set(list(range(N))) - A

        if A == check_group(A):
            if B == check_group(B):
                A_people = 0
                B_people = 0
                for a in A:
                    A_people += people[a]
                for b in B:
                    B_people += people[b]
                
                ans = min(ans, abs(A_people - B_people))

if ans == 1001:
    ans = -1
sys.stdout.write(str(ans))