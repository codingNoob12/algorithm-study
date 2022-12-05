fileNames = []
n = int(input())
for _ in range(n):
    fileNames.append(input())
length = len(fileNames[0])
res = ['?'] * length
for j in range(length):
    for i in range(n):
        if i != n-1:
            if fileNames[i][j] != fileNames[i+1][j]:
                break
        else:
            if fileNames[i][j] != fileNames[0][j]:
                break
    else:
        res[j] = fileNames[0][j]
print(''.join(res))
