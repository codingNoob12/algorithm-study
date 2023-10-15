n = int(input())
dp, recursion = n - 2, 0
dic = {n - 1: 1, n - 2: 1}
k = max(dic.keys())
while k not in (1, 2):
    if k - 1 in dic.keys():
        dic[k - 1] += dic[k]
    else:
        dic[k - 1] = dic[k]
    if k - 2 in dic.keys():
        dic[k - 2] += dic[k]
    else:
        dic[k - 2] = dic[k]
    dic.pop(k)
    k = max(dic.keys())
recursion = sum(dic.values())
print(recursion, dp)
