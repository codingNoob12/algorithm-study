for _ in range(int(input())):
    M, N, K = map(int, input().split())
    square = [[0] * N for _ in range(M)]
    for _ in range(K):
        i, j = map(int, input().split())
        square[i][j] = 1

    group_numbers, stk = [], []
    group_number = -1
    dA = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    for i in range(M):
        for j in range(N):
            stk.append(tuple([i, j]))

            while stk:
                x, y = stk.pop()
                if x < 0 or x >= M or y < 0 or y >= N:
                    continue
                if square[x][y] == 1:
                    square[x][y] = group_number
                    if group_number not in group_numbers:
                        group_numbers.append(group_number)
                    for dx, dy in dA:
                        stk.append((x + dx, y + dy))
            if square[i][j] == group_number:
                group_number -= 1
    print(len(group_numbers))
