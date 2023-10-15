n, length = map(int, input().split())
heights = sorted(map(int, input().split()))
for height in heights:
    if length < height:
        break
    length += 1
print(length)
