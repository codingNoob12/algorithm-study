odds = []
for i in range(7):
    num = int(input())
    if num % 2 != 0:
        odds.append(num)
if len(odds) == 0:
    print(-1)
else:
    print(sum(odds), min(odds))
