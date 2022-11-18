from sys import stdin
t = int(input())
for _ in range(t):
    a, b = map(int, stdin.readline().strip().split(','))
    print(a + b)
