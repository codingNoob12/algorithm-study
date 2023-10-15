import sys
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    res = n + int(str(n)[::-1])
    if str(res) == str(res)[::-1]:
        print('YES')
    else:
        print('NO')
