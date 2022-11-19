t = int(input())
for _ in range(t):
    n, c = map(int, input().split())
    days = n // c if n % c == 0 else n // c + 1
    print(days)
