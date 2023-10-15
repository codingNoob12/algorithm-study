n = int(input())
totRem = 0
for _ in range(n):
    stu, app = map(int, input().split())
    totRem += app % stu
print(totRem)
