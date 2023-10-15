import sys

def getFactors(n):
    factors = []
    for i in range(1, n):
        if n % i == 0:
            factors.append(i)
    return factors


input = sys.stdin.readline
while True:
    n = int(input())
    if n == -1:
        break
    factors = getFactors(n)
    if n == sum(factors):
        print(n, '=', end=' ')
        print(*factors, sep=' + ')
    else:
        print(n, 'is NOT perfect.')
