x = int(input())
n = int(input())
tot = 0
for _ in range(n):
    a, b = map(int, input().split())
    tot += a * b
res = "Yes" if x == tot else "No"
print(res)
