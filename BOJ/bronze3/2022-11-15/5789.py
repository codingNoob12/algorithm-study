from collections import deque
n = int(input())
for i in range(n):
    binary = input()
    biEach = deque(binary)
    while len(biEach) > 2:
        biEach.pop()
        biEach.popleft()
    if biEach[0] == biEach[-1]:
        print('Do-it')
    else:
        print('Do-it-Not')
