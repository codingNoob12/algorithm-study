n = int(input())
factors = [i for i in range(1, n+1) if n % i == 0]
print(sum(factors) * 5 - 24)
