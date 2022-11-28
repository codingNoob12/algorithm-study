from sys import stdin
T = int(input())
chkList = [[10], [1], [2, 4, 8, 6], [3, 9, 7, 1], [4, 6], [5], [6], [7, 9, 3, 1], [8, 4, 2, 6], [9, 1]]
for _ in range(T):
    a, b = map(int, stdin.readline().strip().split())
    print(chkList[a % 10][(b - 1) % len(chkList[a % 10])])
