a, b = map(int, input().split())
inc, leastCrystal = 1, 1
for _ in range(b):
    inc += a - 2
    leastCrystal += inc
print(leastCrystal)
