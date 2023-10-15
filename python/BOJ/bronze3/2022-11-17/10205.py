k = int(input())
for i in range(1, k+1):
    h = int(input())
    for ch in input():
        if ch == 'c':
            h += 1
        else:
            h -= 1
    print(f'Data Set {i}:')
    print(h, end='\n\n')
