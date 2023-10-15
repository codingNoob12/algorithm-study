vowelList = ['a', 'e', 'i', 'o', 'u']
while True:
    line = input()
    if line == "#":
        break
    cnt = 0
    for vowel in vowelList:
        cnt += line.lower().count(vowel)
    print(cnt)
