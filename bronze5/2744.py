word = input()
res = ""
for ch in word:
    if ch.isupper():
        res += ch.lower()
    else:
        res += ch.upper()
print(res)
