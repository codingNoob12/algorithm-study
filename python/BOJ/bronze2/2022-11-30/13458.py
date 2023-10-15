n = int(input())
aList = list(map(int, input().split()))
b, c = map(int, input().split())
cnt = 0
for a in aList:
    cnt += 1
    a -= b
    if a >= 0:
        cnt += a // c if a % c == 0 else a // c + 1
print(cnt)
