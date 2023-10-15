N = int(input())
numLists = [list(map(int, input().split())) for _ in range(N)]
scores = [0] * N
for i, nums in enumerate(numLists):
    for j in range(3):
        for comparison in numLists[:i] + numLists[i+1:]:
            if nums[j] == comparison[j]:
                break
        else:
            scores[i] += nums[j]
print(*scores, sep='\n')
