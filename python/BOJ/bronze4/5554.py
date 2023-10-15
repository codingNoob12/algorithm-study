time = 0
for _ in range(4):
    time += int(input())
m = time // 60
s = time % 60
print(m, s)
