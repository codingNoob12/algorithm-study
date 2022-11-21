n = int(input())
k = 0
for i in range(n):
    if i + 1 + i ** 2 == n:
        k = i
        break
print(k)
