import sys
n = int(sys.stdin.readline().strip())
wordList = set()
for _ in range(n):
    word = sys.stdin.readline().strip()
    wordList.add(word)
wordList = list(wordList)
wordList.sort()
wordList.sort(key=len)
for word in wordList:
    print(word)
