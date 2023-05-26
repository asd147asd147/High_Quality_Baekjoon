import sys

def power(a,b,m):
    result = 1
    while b > 0:
        if b % 2 != 0:
            result = (result * a) % m
        b //= 2
        a = (a * a) % m

    return result

input = sys.stdin.readline

N, K = map(int, input().split())
MOD = 1000000007
fac = [1, 1]
for i in range(2,4000001):
    fac.append(fac[i-1]*i % MOD)

sys.stdout.write(str(fac[N]*power((fac[N-K]*fac[K]), MOD-2, MOD) % MOD))