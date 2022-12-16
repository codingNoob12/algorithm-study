l = int(input())
n = int(input())
rollCake = [0] * (l+1)
expect, actual = 0, -1
expectCnt = 0
for i in range(1, n+1):
    p, k = map(int, input().split())
    for j in range(p, k+1):
        if rollCake[j] == 0:
            rollCake[j] = i
    if expectCnt < k - p + 1:
        expectCnt = k - p + 1
        expect = i
    if rollCake.count(actual) < rollCake.count(i):
        actual = i
print(expect, actual, sep='\n')
