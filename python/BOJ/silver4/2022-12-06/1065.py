cnt = 0
for i in range(1, int(input()) + 1):
    tmp = str(i)
    for j in range(len(tmp) - 2):
        if ord(tmp[j]) + ord(tmp[j + 2]) != 2 * ord(tmp[j + 1]):
            break
    else:
        cnt += 1
print(cnt)
