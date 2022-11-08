n = int(input())
callTime = list(map(int, input().split()))
y = 0
m = 0
for each in callTime:
    y += (each // 30 + 1) * 10
    m += (each // 60 + 1) * 15
if y > m:
    print("M", m)
elif y == m:
    print("Y M", y)
else:
    print("Y", y)
