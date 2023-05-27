import sys

def power(a,b,m):
    if b == 0 or b == 1:
        return a

    p = power(a, b//2, m)
    if b % 2 == 0:
        return p*p % m
    else:
        return (p*p % m) * a % m

MOD = 1000000007

input = sys.stdin.readline

M = int(input())

answer = 0
for _ in range(M):
    N, S = map(int, input().split())
    answer = (answer + S * power(N, MOD-2, MOD)) % MOD

sys.stdout.write(str(answer))