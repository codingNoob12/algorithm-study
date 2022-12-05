n = int(input())
b = list(map(int, input().split()))
a = []
for i in range(n):
    last = b[i-1] if i > 0 else 0
    a.append((i+1) * b[i] - i * last)
print(*a)
