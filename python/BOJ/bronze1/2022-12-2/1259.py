import sys
input = sys.stdin.readline
while True:
    num = input().strip()
    if num == '0':
        break
    print('yes' if num == num[::-1] else 'no')
