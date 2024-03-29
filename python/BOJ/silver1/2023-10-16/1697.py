from collections import deque

MAX_SIZE = 10 ** 5
times = [0] * (MAX_SIZE + 1)
n, k = map(int, input().split())

q = deque([n])
while q:
    x = q.popleft()
    if x == k:
        print(times[x])
        break
    for nx in (x - 1, x + 1, x * 2):
        if 0 <= nx <= MAX_SIZE and times[nx] == 0:
            times[nx] = times[x] + 1
            q.append(nx)

# note)
# 이 문제는 방문 가능한 모든 경우에 대해서, 방문한 위치가 k와 동일한지 체크하면 된다.
# n에서 시작해 방문 가능한 위치는 한 step에 n-1, n+1, n*2가 가능하다.
# step이 제한적이지만, 모든 경우를 일일히 고려하기 어려우므로 BFS로 모든 경우의 수를 관리하는 것이 편리하다.
# 하지만 위의 문제에서는, N, K의 범위가 0 ~ 100,000이므로 시간 복잡도가 O(3^D)인 BFS로는 최악의 경우 시간 초과가 난다.
# 또한, 공간 복잡도도 최악을 고려하면, O(3^D)로 메모리 초과가 날 수 있다.
# 이러한 문제를 방지하려면, 재방문을 하지 않아야 하며, 큐를 최소한으로 사용해야한다.
#
# 1. times 리스트를 이용해 해당 지점에 도달하는 시간을 관리하도록 한다.
# 경우의 수를 관리하는 것은 BFS가 편리하므로 경우의 수만을 큐에 담아보자. (통과 안되면, 다른 방법으로 접근하자)
# 2. 방문을 하면, times의 해당 인덱스의 시간을 갱신한다.
# 이때, 재방문을 한다면, 최단 시간으로 해당 지점에 도착한 것이 아님을 보장한다. 따라서, 시간이 0인 지점만 갱신하자.
#
# 결과: pass
