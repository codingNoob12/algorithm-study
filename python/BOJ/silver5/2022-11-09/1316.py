n = int(input())
cnt = n
for i in range(n):
    word = input()
    chkList = []
    for ch in word:
        if ch in chkList and ch != chkList[-1]:
            cnt -= 1
            break
        chkList.append(ch)
print(cnt)
