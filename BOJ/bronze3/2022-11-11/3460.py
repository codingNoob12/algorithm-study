t = int(input())
for _ in range(t):
    bi = bin(int(input()))
    bi = bi[::-1]
    for i in range(len(bi)):
        if bi[i] == '1':
            print(i, end=' ')
