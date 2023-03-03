def merge_sort(A, p, r):
    if p < r:
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)

def merge(A, p, q, r):
    global tmp, cnt, ans
    i, j, t = p, q + 1, 0
    
    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            i += 1
        else:
            tmp[t] = A[j]
            j += 1
        t += 1
    
    for idx in range(i, q + 1):
        tmp[t] = A[idx]
        t += 1
    
    for idx in range(j, r + 1):
        tmp[t] = A[idx]
        t += 1
    
    t = 0
    for idx in range(p, r + 1):
        A[idx] = tmp[t]
        t += 1
        cnt += 1
        if k == cnt:
            ans = A[idx]

n, k = map(int, input().split())
cnt, ans = 0, -1
A = list(map(int, input().split()))
tmp = [0] * len(A)
merge_sort(A, 0, len(A) - 1)
print(ans)