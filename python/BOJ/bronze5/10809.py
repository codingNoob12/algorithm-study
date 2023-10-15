word = input()
checkList = []
for i in range(26):
    idx = word.find(chr(97 + i))
    checkList.append(idx)
for i in checkList:
    print(i, end=' ')
