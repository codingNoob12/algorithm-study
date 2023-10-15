from sys import stdin
t = int(input())
for line in stdin.readlines():
    nums = list(map(int, line.strip().split()))
    print(sum(nums))
