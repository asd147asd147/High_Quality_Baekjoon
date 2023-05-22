import sys
from itertools import permutations
import copy

def rotate(A, r, c, i):
    temp = A[r-i][c-i]
    for y in range(r-i, r+i):
        A[y][c-i] = A[y+1][c-i]
    
    for x in range(c-i, c+i):
        A[r+i][x] = A[r+i][x+1]

    for y in range(r+i, r-i, -1):
        A[y][c+i] = A[y-1][c+i]

    for x in range(c+i, c-i, -1):
        A[r-i][x] = A[r-i][x-1]

    A[r-i][c-i+1] = temp


input = sys.stdin.readline

N, M, K = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(N)]

ans = 500000
rotations = []
for _ in range(K):
    r, c, s = map(int, input().split())
    rotations.append((r-1,c-1,s))

for rotations in permutations(rotations):
    A_temp = copy.deepcopy(A)
    for rotation in rotations:
        r, c, s = rotation
        for i in range(1, s+1):
            rotate(A_temp, r, c, i)
    for a in A_temp:
        ans = min(ans, sum(a))
sys.stdout.write(str(ans))