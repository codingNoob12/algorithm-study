import sys
input = sys.stdin.readline
posList = [tuple(map(int, input().split())) for _ in range(int(input()))]
posList.sort(key=lambda x: (x[1], x[0]))
for pos in posList:
    print(*pos)
