def t(n):
    return (n * (n + 1)) // 2

def w(n):
    sumVal = 0
    for i in range(1, n+1):
        sumVal += i * t(i + 1)
    return sumVal

tc = int(input())
for _ in range(tc):
    n = int(input())
    print(w(n))
