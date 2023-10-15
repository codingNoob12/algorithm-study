n, k = map(int, input().split())
isPrimeList = [False, False] + [True] * (n - 1)

cnt = 0
for i in range(2, n + 1):
    for j in range(i, n + 1, i):
        if isPrimeList[j]:
            cnt += 1
            if cnt == k:
                print(j)
                exit(0)
        isPrimeList[j] = False
