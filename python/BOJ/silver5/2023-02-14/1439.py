s = input()
idx = 0
chunks = {}
for i, ch in enumerate(s):
    if i < len(s) - 1 and s[i + 1] == ch:
        continue
    if ch not in chunks:
        chunks[ch] = [s[idx:i+1]]
    else:
        chunks[ch].append(s[idx:i+1])
    idx = i + 1
if len(chunks) == 1:
    print(0)
else:
    print(min(map(len, chunks.values())))
