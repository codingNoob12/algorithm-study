n = int(input())
m = int(input())
maxSj, sj = m, m
for i in range(n):
    carIn, carOut = map(int, input().split())
    sj += carIn - carOut
    if maxSj < sj:
        maxSj = sj
    elif sj < 0:
        maxSj = 0
        break
print(maxSj)
