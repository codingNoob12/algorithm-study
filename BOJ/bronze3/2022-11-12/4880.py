while True:
    nums = list(map(int, input().split()))
    if nums[0] == nums[1] == nums[2] == 0:
        break
    if nums[1] - nums[0] == nums[2] - nums[1]:
        print('AP', nums[2] + nums[1] - nums[0])
    else:
        print('GP', nums[2] * (nums[2] // nums[1]))
