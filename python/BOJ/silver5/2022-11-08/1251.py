word = input()
n = len(word)
ansList = []
for i in range(n):
    sub1 = word[:i+1]
    sub2 = ""
    sub3 = ""
    for j in range(i + 1, n - 1):
        sub2 = word[i+1:j+1]
        sub3 = word[j+1:]
        ansList.append(sub1[::-1] + sub2[::-1] + sub3[::-1])
ansList.sort()
print(ansList[0])
