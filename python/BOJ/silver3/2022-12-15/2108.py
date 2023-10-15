import sys

input = sys.stdin.readline

nums = [int(input()) for _ in range(int(input()))]
arithmeticMean = round(sum(nums) / len(nums))
nums.sort()
median = nums[len(nums) // 2]
cntDict = {}
for num in nums:
    if num in cntDict.keys():
        cntDict[num] += 1
    else:
        cntDict[num] = 1
maxCnt = max(cntDict.values())
mode = 0
candidates = []
for k, v in cntDict.items():
    if v == maxCnt:
        candidates.append(k)
if len(candidates) > 1:
    candidates.sort()
    mode = candidates[1]
else:
    mode = candidates[0]
range = max(nums) - min(nums)
print(arithmeticMean, median, mode, range, sep='\n')
