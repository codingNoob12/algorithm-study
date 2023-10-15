import sys

input = sys.stdin.readline
SCORES = {}
for _ in range(int(input().rstrip())):
    name, *scores = input().split()
    SCORES[name] = list(map(int, scores))

SCORES = dict(sorted(SCORES.items(), key=lambda x: (-x[1][0], x[1][1], -x[1][2], x[0])))
print(*SCORES.keys(), sep="\n")
