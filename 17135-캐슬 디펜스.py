import sys
import copy

archers_combination = []
input = sys.stdin.readline
N, M, D = map(int, input().split())
answer = 0

def minimum_dist_enemy(board, archer):
    distance = 50
    enemy = None
    for i in range(len(board)):
        for j in range(M):
            if not board[i][j]: continue
            dist = abs(archer[0]-i)+abs(archer[1]-j)
            if dist <= D:
                if dist < distance:
                    distance = dist
                    enemy = (i,j)
                elif dist == distance and j < enemy[1]:
                    enemy = (i,j)
    return enemy

def game(board, archers):
    kill = 0
    while board:
        enemies = []
        for idx, archer in enumerate(archers):
            if not archer: continue

            enemy = minimum_dist_enemy(board, (len(board), idx))
            if enemy is not None:
                enemies.append(enemy)
        enemies = list(set(enemies))
        kill += len(enemies)
        for enemy in enemies:
            board[enemy[0]][enemy[1]] = 0
        board.pop()
    return kill

def backtracking(archers, idx, cnt):
    if cnt==3:
        archers_combination.append(archers)
        return

    for i in range(idx, len(archers)):
        if archers[i]: continue

        archers[i] = True
        backtracking(copy.deepcopy(archers), i+1, cnt+1)
        archers[i] = False



board = [list(map(int, input().split())) for _ in range(N)]
archers = [False for _ in range(M)]

backtracking(archers, 0, 0)

for archers in archers_combination:
    answer = max(answer, game(copy.deepcopy(board), archers))

sys.stdout.write(str(answer))