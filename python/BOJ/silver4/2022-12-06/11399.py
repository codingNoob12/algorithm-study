n = int(input())
processingTimes = list(map(int, input().split()))
processingTimes.sort()
res = 0
for i in range(1, n+1):
    res += sum(processingTimes[:i])
print(res)
