import sys
input = sys.stdin.readline
members = []
for i in range(int(input())):
    age, name = input().strip().split()
    members.append((int(age), i, name))
members.sort()
for member in members:
    print(member[0], member[-1])
