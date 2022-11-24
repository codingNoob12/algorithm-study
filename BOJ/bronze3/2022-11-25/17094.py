strLen = int(input())
numOf2 = input().count('2')
if strLen > 2 * numOf2:
    print('e')
elif strLen < 2 * numOf2:
    print(2)
else:
    print('yee')
