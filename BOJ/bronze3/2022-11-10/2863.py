def rotate(a, b, c, d):
    return c, a, d, b

def getVal(a, b, c, d):
    return a / c + b / d

a, b = map(int, input().split())
c, d = map(int, input().split())
maxVal = getVal(a, b, c, d)
cnt = 0
for i in range(3):
    a, b, c, d = rotate(a, b, c, d)
    tmp = getVal(a, b, c, d)
    if maxVal < tmp:
        maxVal = tmp
        cnt = i + 1
print(cnt)
