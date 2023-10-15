import sys

input = sys.stdin.readline
a = [False, False] + [True] * (10000 - 1)
primes = []
for i in range(2, 10001):
    if a[i]:
        primes.append(i)
        for j in range(2 * i, 10001, i):
            a[j] = False

for _ in range(int(input().rstrip())):
    n = int(input().rstrip())
    i = 0
    while primes[i] <= n // 2:
        i += 1
    i -= 1
    while n - primes[i] not in primes:
        i -= 1
        if i < 0:
            break
    else:
        print(primes[i], n - primes[i])
