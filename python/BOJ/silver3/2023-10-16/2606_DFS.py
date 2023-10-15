n = int(input())
graph = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(int(input())):
    u, v = map(int, input().split())
    graph[u][v], graph[v][u] = 1, 1

start = 1
visited, stk = [], [start]
while stk:
    node = stk.pop()
    if node not in visited:
        visited.append(node)

    for i, e in enumerate(graph[node]):
        if e == 1 and i not in visited:
            stk.append(i)
print(len(visited) - 1)
