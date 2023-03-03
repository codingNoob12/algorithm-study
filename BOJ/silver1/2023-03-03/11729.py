def hanoi(n, a = 1, b = 2, c = 3):
    global cnt
    if n == 1:
        resList.append((a, c))
        return

    hanoi(n - 1, a, c, b)
    resList.append((a, c))
    hanoi(n - 1, b, a, c)

n = int(input())
resList = []
hanoi(n)
print(len(resList))
for res in resList:
    print(*res)