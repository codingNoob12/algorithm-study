n = int(input())
for i in range(1, n+1):
    name = input()
    print(f'String #{i}')
    for ch in name:
        tmp = ord(ch) + 1
        if tmp > ord('Z'):
            tmp = ord('A')
        print(chr(tmp), end='')
    print('\n')
