N, m, M, T, R = map(int, input().split())
X, i, cnt = m, 0, 0
while i < N:
    if X + T > M:
        if X - R < m:
            X = m
            if X + T > M:
                print(-1)
                exit(0)
        else:
            X -= R
    else:
        X += T
        i += 1
    cnt += 1
print(cnt)
