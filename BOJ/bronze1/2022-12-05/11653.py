n = int(input())
factorDict, i = {}, 2
while n != 1:
    if n % i == 0:
        if i in factorDict.keys():
            factorDict[i] += 1
        else:
            factorDict[i] = 1
        n //= i
    else:
        i += 1
for k, v in factorDict.items():
    for i in range(v):
        print(k)
