t = int(input())
for i in range(t):
    input()
    n = int(input())
    candies = 0
    for j in range(n):
        candies += int(input())
    if candies % n == 0:
        print("YES")
    else:
        print("NO")
