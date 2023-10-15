import sys
input = sys.stdin.readline
for _ in range(int(input())):
    for word in input().strip().split():
        print(word[::-1], end=' ')
    print()
