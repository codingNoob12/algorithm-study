word = input()
for i in range(26):
    ch = chr(97 + i)
    print(word.count(ch), end=" ")
