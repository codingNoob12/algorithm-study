# # 파이썬 list 이용 (배열)... 0.3초 이내에 삽입 삭제가 불가능
# import sys
# input = sys.stdin.readline
# st = [ch for ch in input().rstrip()]
# cursor = len(st)
# for _ in range(int(input())):
#     cmd = input().strip().split()
#     if len(cmd) == 1:
#         if cmd[0] == 'L':
#             if cursor != 0:
#                 cursor -= 1
#         elif cmd[0] == 'D':
#             if cursor != len(st):
#                 cursor += 1
#         else:
#             if cursor != 0:
#                 cursor -= 1
#                 st.pop(cursor)
#     else:
#         st.insert(cursor, cmd[1])
#         cursor += 1
# print(''.join(st))

import sys
from collections import deque
input = sys.stdin.readline
st1 = deque(input().rstrip())
st2 = deque()
for _ in range(int(input())):
    cmd = input().strip().split()
    if cmd[0] == 'L' and st1:
        st2.appendleft(st1.pop())
    elif cmd[0] == 'D' and st2:
        st1.append(st2.popleft())
    elif cmd[0] == 'B' and st1:
        st1.pop()
    elif len(cmd) == 2:
        st1.append(cmd[1])
print(*(st1 + st2), sep='')
