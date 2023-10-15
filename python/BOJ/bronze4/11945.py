n, m = map(int, input().split())
bread = []
for _ in range(n):
    bread.append(input()[-1::-1])
for row in bread:
    print(row)
