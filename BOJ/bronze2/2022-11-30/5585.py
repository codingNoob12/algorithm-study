money = 1000 - int(input())
changeList = [500, 100, 50, 10, 5, 1]
cnt = 0
for change in changeList:
    cnt += money // change
    money %= change
print(cnt)
