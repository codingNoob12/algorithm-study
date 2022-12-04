def d(n):
    res = n
    for ch in str(n):
        res += int(ch)
    return res

dic = {d(i): 1 for i in range(1, 10001)}
for i in range(1, 10001):
    if dic.get(i) is None:
        print(i)
