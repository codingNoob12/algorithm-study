# n, m = map(int, input().split())
# STRINGS = {input() for _ in range(n)}
# cnt = 0
# for _ in range(m):
#     check = input()
#     if check in STRINGS:
#         cnt += 1
# print(cnt)

n, m = map(int, input().split())
STRINGS = {}
for _ in range(n):
    s = input()
    if s not in STRINGS:
        STRINGS[s] = 1
cnt = 0
for _ in range(m):
    check = input()
    if check in STRINGS:
        cnt += 1
print(cnt)
