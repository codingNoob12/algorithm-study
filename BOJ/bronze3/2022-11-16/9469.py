p = int(input())
for i in range(1, p+1):
    n, d, a, b, f = map(float, input().split())
    t = d / (a + b)
    dist = t * f
    print(i, dist)
