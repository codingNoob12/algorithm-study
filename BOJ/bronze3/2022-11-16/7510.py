n = int(input())
for i in range(1, n+1):
    nums = list(map(int, input().split()))
    nums.sort()
    print(f'Scenario #{i}:')
    if nums[2] ** 2 == nums[1] ** 2 + nums[0] ** 2:
        print('yes')
    else:
        print('no')
    print()
