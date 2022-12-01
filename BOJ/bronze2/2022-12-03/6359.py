def change(lst, k):
    for i in range(len(lst)):
        if (i + 1) % k == 0:
            lst[i] = not lst[i]

for _ in range(int(input())):
    n = int(input())
    isLock = [False] * n
    for i in range(1, n+1):
        change(isLock, i)
    print(sum(isLock))
