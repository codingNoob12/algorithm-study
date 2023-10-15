# x, cnt = int(input()), 0
# while x >= 10:
#     y = sum(map(int, str(x)))
#     x = y
#     cnt += 1
# print(cnt)
# print("YES" if x in (3, 6, 9) else "NO")


# int => str 변환하는 것을 안하면 시간이 더 줄어듬
x = input()
cnt = 0
while len(x) >= 2:
    y = sum(map(int, x))
    x = str(y)
    cnt += 1
print(cnt)
print("YES" if int(x) in (3, 6, 9) else "NO")
