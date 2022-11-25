idealMBTI = []
for ch in input():
    if ch == 'E':
        idealMBTI.append('I')
    elif ch == 'I':
        idealMBTI.append('E')
    elif ch == 'S':
        idealMBTI.append('N')
    elif ch == 'N':
        idealMBTI.append('S')
    elif ch == 'T':
        idealMBTI.append('F')
    elif ch == 'F':
        idealMBTI.append('T')
    elif ch == 'J':
        idealMBTI.append('P')
    else:
        idealMBTI.append('J')
print(''.join(idealMBTI))
