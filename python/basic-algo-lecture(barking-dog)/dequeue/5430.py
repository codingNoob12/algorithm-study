# for _ in range(int(input())):
#     p = input()
#     n = int(input())
#     if n:
#         nums = list(map(int, input()[1:-1].split(',')))
#     else:
#         input()
#         nums = []
#     idx = 0
#     for func in p:
#         if func == 'R':
#             idx = 0 if idx else -1
#         else:
#             if nums:
#                 nums.pop(idx)
#             else:
#                 print('error')
#                 break
#     else:
#         print('[', end='')
#         if idx:
#             nums.reverse()
#         print(*nums, sep=',', end='')
#         print(']')

from collections import deque
for _ in range(int(input())):
    p = input()
    n = int(input())
    if n:
        nums = deque(input()[1:-1].split(','))
    else:
        input()
        nums = deque()
    reverse = False
    for func in p:
        if func == 'R':
            reverse = not reverse
        else:
            if nums:
                if reverse:
                    nums.pop()
                else:
                    nums.popleft()
            else:
                print('error')
                break
    else:
        if reverse:
            nums.reverse()
        print('[' + ','.join(nums) + ']')

# 이 문제를 덱으로 플어야 더 빠른 이유는 list로 풀면 삭제할때 오버헤드가 심해서 그냥 연결리스트로 구현된 덱을 이용하는게 빠르다
