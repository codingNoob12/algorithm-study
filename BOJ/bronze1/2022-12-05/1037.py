n = int(input())
factors = list(map(int, input().split()))
res = max(factors) * min(factors)
print(res)
