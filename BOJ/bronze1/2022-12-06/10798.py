strings = [input() for _ in range(5)]
res = []
for i in range(15):
    for j in range(5):
        for k in range(len(strings[j])):
            if i == k:
                res.append(strings[j][k])
print(''.join(res))
