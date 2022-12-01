censoredCharacters = 'CAMBRIDGE'
for ch in input():
    if ch in censoredCharacters:
        continue
    print(ch, end='')
