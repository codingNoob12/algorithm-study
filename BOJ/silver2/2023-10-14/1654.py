K, N = map(int, input().split())
lengths = [int(input()) for _ in range(K)]
start, end = 1, max(lengths)
while start < end:
    mid = (start + end) // 2

    count = 0
    for length in lengths:
        count += length // mid

    if count < N:
        end = mid - 1
    else:
        start = mid + 1
print(end)
