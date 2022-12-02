def binarySearch(a, x, start, end):
    if start < 0 or start > end:
        return 0
    mid = (start + end) // 2
    if a[mid] == x:
        return 1
    elif a[mid] > x:
        return binarySearch(a, x, start, mid-1)
    else:
        return binarySearch(a, x, mid+1, end)

n = int(input())
aList = sorted(list(map(int, input().split())))
m = int(input())
for num in list(map(int, input().split())):
    print(binarySearch(aList, num, 0, n-1))
