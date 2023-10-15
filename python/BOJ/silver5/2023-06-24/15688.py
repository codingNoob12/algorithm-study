import sys

n = int(sys.stdin.readline())
print(*sorted(map(int, map(str.rstrip, sys.stdin.readlines()))), sep='\n')
