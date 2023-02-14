import sys

input = sys.stdin.readline
n = int(input().rstrip())
weights = sorted([int(input().rstrip()) for _ in range(n)], reverse=True)
candidates = []
while weights:
    candidates.append(weights[-1] * len(weights))
    weights.pop()
print(max(candidates))
