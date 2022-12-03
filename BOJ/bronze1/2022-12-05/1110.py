n = input()
tmp, cnt = n, 0
while True:
    t = 0
    for ch in tmp:
        t += int(ch)
    tmp = tmp[-1] + str(t % 10)
    cnt += 1
    if int(tmp) == int(n):
        break
print(cnt)
