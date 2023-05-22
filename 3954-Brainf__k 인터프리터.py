import sys
import copy

def find_loop(cmd):
    jump = {}
    brackets = []
    for i, c in enumerate(cmd):
        if c == '[':
            brackets.append(i)
        elif c == ']':
            to = brackets.pop()
            jump[i] = to
            jump[to] = i
    return jump

input = sys.stdin.readline

T = int(input())
while T > 0:
    M, C, I = map(int, input().split())
    cmd = input().rstrip()
    string = input().rstrip()

    array = [0 for _ in range(M)]
    cnt = 0
    array_ptr = 0
    cmd_ptr = 0
    string_ptr = 0

    jump = find_loop(cmd)
    max_ptr = C
    flag = False

    while cmd_ptr < C:
        cnt+=1
        c = cmd[cmd_ptr]

        if c == '+':
            array[array_ptr] += 1
            array[array_ptr] %= 2**8
        elif c == '-':
            array[array_ptr] -= 1
            array[array_ptr] %= 2**8
        elif c == '<':
            array_ptr -= 1
            array_ptr %= M
        elif c == '>':
            array_ptr += 1
            array_ptr %= M
        elif c == '[':
            if array[array_ptr] == 0:
                cmd_ptr = jump[cmd_ptr]
        elif c == ']':
            if array[array_ptr] != 0:
                cmd_ptr = jump[cmd_ptr]
        elif c == ',':
            if string_ptr < len(string):
                array[array_ptr] = ord(string[string_ptr])
                string_ptr+=1
            else:
                array[array_ptr] = 255

        if cnt > 50000000:
            max_ptr = min(max_ptr, cmd_ptr)
        cmd_ptr+=1

        if cnt > 2*50000000:
            flag = True
            sys.stdout.write('Loops {} {}\n'.format(max_ptr, jump[max_ptr]))
            break
    if not flag:
        sys.stdout.write('Terminates\n')
    T-=1