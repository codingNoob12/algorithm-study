import sys

def binary_search(ls: list, data, s, e):
    while s <= e:
        m = (s + e) // 2
        if ls[m] == data:
            return 1
        if ls[m] > data:
            e = m - 1
        else:
            s = m + 1
    return 0

input = sys.stdin.readline
n = int(input())
having = list(map(int, input().split()))
m = int(input())
check = list(map(int, input().split()))
having.sort()
print(*[binary_search(having, num, 0, n - 1) for num in check])
