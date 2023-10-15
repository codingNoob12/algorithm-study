n = int(input())
a = []
for i in range(1, n):
    a.append(i)
for i in range(n, 1001):
    for j in range(2, i):
        if i % j == 0:
            break
    else:
        a.append(i)
        break
print(n)
print(*a)
