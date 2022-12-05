n, p = map(int, input().split())
nodes, node, cnt = {n: 1}, n, 0
while True:
    node = node * n % p
    if node in nodes.keys():
        nodes[node] += 1
        if nodes[node] == 2:
            cnt += 1
    else:
        nodes[node] = 1
    if 3 in nodes.values():
        break
print(cnt)
