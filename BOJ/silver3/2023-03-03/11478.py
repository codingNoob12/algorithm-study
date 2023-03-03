s = input()
n = len(s)
substrings = set()

for l in range(1, n+1):
    for i in range(n - l + 1):
        substrings.add(s[i:i+l])
print(len(substrings))