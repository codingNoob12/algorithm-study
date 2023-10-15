import math

m = int(input())
n = int(input())
primes = []
s = m if m != 1 else 2
e = n
for i in range(s, e + 1):
    for j in range(2, int(math.sqrt(i)) + 1):
        if i % j == 0:
            break
    else:
        primes.append(i)
if primes:
    print(sum(primes), primes[0], sep='\n')
else:
    print(-1)
