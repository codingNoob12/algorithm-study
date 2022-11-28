nums = list(map(int, input().split()))
asc = list(range(1, 9))
des = list(range(8, 0, -1))
if nums == asc:
    print('ascending')
elif nums == des:
    print('descending')
else:
    print('mixed')
