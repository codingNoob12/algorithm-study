s, cnt, i = input(), 0, 0
while i < len(s):
    if s[i:i+3] == 'dz=':
        i += 2
    elif s[i:i+2] in ('c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z='):
        i += 1
    i += 1
    cnt += 1
print(cnt)
