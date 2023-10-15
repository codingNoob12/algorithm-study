n, m = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
mem = 0
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            tmp = nums[i] + nums[j] + nums[k]
            if tmp > m:
                break
            if mem < tmp:
                mem = tmp
print(mem)
