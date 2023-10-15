from collections import deque

def dfs(graph, start):
    visited, stk = [start], [start]

    node = start
    while stk:
        for i, e in enumerate(graph[node]):
            if e == 1 and i not in visited:
                stk.append(node)
                node = i
                visited.append(node)
                break
        else:
            node = stk.pop()
    print(*visited)

def bfs(graph, start):
    visited, queue = [start], deque([start])

    while queue:
        node = queue.popleft()

        for i, e in enumerate(graph[node]):
            if e == 1 and i not in visited:
                node = i
                queue.append(node)
                visited.append(node)
    print(*visited)

N, M, V = map(int, input().split())
graph = [[0] * (N + 1) for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b], graph[b][a] = 1, 1

dfs(graph, V)
bfs(graph, V)
