from sys import stdin
k = int(stdin.readline().strip())
n = int(stdin.readline().strip())
totTime = 0
for _ in range(n):
    t, ans = stdin.readline().split()
    totTime += int(t)
    if totTime >= 210:
        break
    if ans == 'T':
        k += 1
    k = (k - 1) % 8 + 1
print(k)
