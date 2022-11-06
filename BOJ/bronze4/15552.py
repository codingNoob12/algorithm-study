import sys

t = int(input())
for _ in range(t):
    a, b = map(int, sys.stdin.readline().strip().split())
    sumVal = a + b
    print(sumVal)
