seq = [i for i in range(1, 1001) for j in range(i)]
a, b = map(int, input().split())
print(sum(seq[a-1:b]))
