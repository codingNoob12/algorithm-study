import copy

n, m = map(int, input().split())
basket = [i for i in range(n + 1)]
for _ in range(m):
    i, j, k = map(int, input().split())
    L, R = copy.deepcopy(basket[i:k]), copy.deepcopy(basket[k : j + 1])
    basket[i : j + 1] = R + L
print(*basket[1:])
