encrypts = []
for ch in input():
    if 65 <= ord(ch) <= 77 or 97 <= ord(ch) <= 109:
        ch = chr(ord(ch) + 13)
    elif 78 <= ord(ch) <= 90 or 110 <= ord(ch) <= 122:
        ch = chr(ord(ch)-13)
    encrypts.append(ch)
print(''.join(encrypts))
