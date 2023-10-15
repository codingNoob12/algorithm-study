from sys import stdin
t = int(input())
for _ in range(t):
    n = int(stdin.readline())
    totPro = 0
    for _ in range(n):
        proList = list(map(int, stdin.readline().strip().split()))
        maxPro = max(proList) if max(proList) >= 0 else 0
        totPro += maxPro
    print(totPro)
