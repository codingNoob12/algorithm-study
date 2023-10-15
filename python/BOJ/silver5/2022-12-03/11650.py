import sys
input = sys.stdin.readline
posList = [tuple(map(int, input().split())) for _ in range(int(input()))]
for x, y in sorted(posList):
    print(x, y)
