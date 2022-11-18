from sys import stdin
t = int(input())
for _ in range(t):
    n = int(input())
    totCredit, GPA = 0, 0
    for _ in range(n):
        c, g = map(float, stdin.readline().strip().split())
        totCredit += int(c)
        GPA += c * g
    GPA = round(GPA / totCredit, 1)
    print(totCredit, GPA)
