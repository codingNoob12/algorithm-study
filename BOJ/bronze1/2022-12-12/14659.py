n = int(input())
heights = list(map(int, input().split()))
current, kill, maxKill = 0, 0, 0
for height in heights:
    if height > current:
        current = height
        kill = 0
    else:
        kill += 1
    if kill > maxKill:
        maxKill = kill
print(maxKill)
