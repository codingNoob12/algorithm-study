s = input()
suffixes = []
for i in range(len(s)):
    suffixes.append(s[i:])
print(*sorted(suffixes), sep="\n")
