n = int(input())
mirror = [input() for _ in range(n)]
k = int(input())
if k == 3:
    mirror.reverse()
for line in mirror:
    if k == 2:
        line = line[::-1]
    print(line)
