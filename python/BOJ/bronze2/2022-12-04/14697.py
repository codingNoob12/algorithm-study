a, b, c, n = map(int, input().split())
for i in range(n // a + 1):
    for j in range((n - a * i) // b + 1):
        for k in range((n - a * i - b * j) // c + 1):
            if a * i + b * j + c * k == n:
                print(1)
                exit(0)
print(0)
