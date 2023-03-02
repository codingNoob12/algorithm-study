n, m = map(int, input().split())
basket = [i for i in range(n + 1)]
for _ in range(m):
    i, j = map(int, input().split())
    basket[i : j + 1] = basket[j : i - 1 : -1]
print(*basket[1:])
