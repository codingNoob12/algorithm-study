n, m = map(int, input().split())
ary1 = [list(map(int, input().split())) for i in range(n)]
ary2 = [list(map(int, input().split())) for i in range(n)]
sumOfAry = []
for i in range(n):
    sumOfAry.append(list())
    for j in range(m):
        sumOfAry[i].append(ary1[i][j] + ary2[i][j])
for i in range(n):
    for j in range(m):
        print(sumOfAry[i][j], end=' ')
    print()
