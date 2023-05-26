import sys
from itertools import permutations

input = sys.stdin.readline

N = int(input())

oprand = list(map(int, input().split()))

op_list = ['+', '-', '*', '//']
oprator = list(map(int, input().split()))

oprator = [op_list[i] for i in range(4) if oprator[i] for _ in range(oprator[i])]

oprators = permutations(oprator, len(oprator))
oprators = list(set(oprators))

min_ans = 10**9
max_ans = -min_ans

for oprator in oprators:
    num = oprand[0]
    for n, o in zip(oprand[1:], oprator):
        if num < 0 and o == '//':
            num = -(abs(num) // n)
        else:
            num = eval(str(num)+o+str(n))
    
    min_ans = min(min_ans, num)
    max_ans = max(max_ans, num)

sys.stdout.write(str(max_ans)+'\n'+str(min_ans))