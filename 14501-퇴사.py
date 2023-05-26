import sys

    

input = sys.stdin.readline

N = int(input())

cansult = []
for _ in range(N):
    T, P = map(int, input().split())
    cansult.append((T,P))

visited = [ False ] * N
ans = 0
def backtracking(idx, earn):
    global ans
    if idx == N:
        ans = max(ans, earn)
        return

    if idx+cansult[idx][0] <= N:
        for t in range(cansult[idx][0]):
            visited[idx+t] = True

        backtracking(idx+cansult[idx][0], earn+cansult[idx][1])

        for t in range(cansult[idx][0]):
            visited[idx+t] = False
    backtracking(idx+1, earn)

for i in range(N):
    if i+cansult[i][0] > N: continue

    for t in range(cansult[i][0]):
        visited[i+t] = True

    backtracking(i+cansult[i][0], cansult[i][1])

    for t in range(cansult[i][0]):
        visited[i+t] = False

sys.stdout.write(str(ans))