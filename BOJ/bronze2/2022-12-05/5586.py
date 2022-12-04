joi, ioi = 0, 0
st = input()
for i in range(len(st)):
    if 'JOI' == st[i:i+3]:
        joi += 1
    elif 'IOI' == st[i:i+3]:
        ioi += 1
print(joi, ioi, sep='\n')
