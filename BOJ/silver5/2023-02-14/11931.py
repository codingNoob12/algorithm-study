import sys
input = sys.stdin.readline
n = int(input().rstrip())
nums = sorted([int(input().rstrip()) for _ in range(n)], reverse=True)
print(*nums, sep='\n')
