n = int(input())
wcA, wcB = 0, 0
for i in range(n):
    a, b = map(int, input().split())
    if a > b:
        wcA += 1
    elif a < b:
        wcB += 1
print(wcA, wcB)
