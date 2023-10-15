# sol 1)
# import sys
# input = sys.stdin.readline
# S = set()
# for _ in range(int(input().rstrip())):
#     cmdline = input().rstrip()
#     if cmdline not in ('all', 'empty'):
#         cmd, value = cmdline.split()
#         value = int(value)
#         if cmd == 'add':
#             S.add(value)
#         elif cmd == 'remove' and value in S:
#             S.remove(value)
#         elif cmd == 'check':
#             print(1 if value in S else 0)
#         elif cmd == 'toggle':
#             if value in S:
#                 S.remove(value)
#             else:
#                 S.add(value)
#     else:
#         cmd = cmdline
#         if cmd == 'all':
#             S = set(range(1, 21))
#         elif cmd == 'empty':
#             S = set()


# sol 2)
# import sys
# input = sys.stdin.readline
# S = set()
# for _ in range(int(input().rstrip())):
#     cmd, *args = input().rstrip().split()
#     value = int(args[0]) if args else None
#     if cmd == 'add':
#         S.add(value)
#     elif cmd == 'remove' and value in S:
#         S.remove(value)
#     elif cmd == 'check':
#         print(1 if value in S else 0)
#     elif cmd == 'toggle':
#         if value in S:
#             S.remove(value)
#         else:
#             S.add(value)
#     elif cmd == 'all':
#         S = set(range(1, 21))
#     elif cmd == 'empty':
#         S = set()


# sol 3)
## 이렇게 짜도 거의 4초임... 의미 없더라
import sys
input = sys.stdin.readline
bits = [0] * 21
for _ in range(int(input().rstrip())):
    cmd, *args = input().rstrip().split()
    value = int(args[0]) if args else None
    if cmd == 'add':
        bits[value] = 1
    elif cmd == 'remove':
        bits[value] = 0
    elif cmd == 'check':
        print(bits[value])
    elif cmd == 'toggle':
        bits[value] = 1 - bits[value]
    elif cmd == 'all':
        bits = [1] * 21
    elif cmd == 'empty':
        bits = [0] * 21
