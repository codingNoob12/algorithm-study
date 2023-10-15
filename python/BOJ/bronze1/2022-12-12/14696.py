import sys

input = sys.stdin.readline

def getResult(aList: list, bList: list):
    for i in range(4, 0, -1):
        aCnt = aList.count(i)
        bCnt = bList.count(i)
        if aCnt > bCnt:
            return 'A'
        elif aCnt < bCnt:
            return 'B'
    return 'D'

for _ in range(int(input())):
    aList = list(map(int, input().split()))
    bList = list(map(int, input().split()))
    print(getResult(aList[1:], bList[1:]))
