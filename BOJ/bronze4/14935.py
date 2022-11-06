init = input()
a = init
ret = None
cnt = 0
while a != ret and cnt != 10000000:
    ret = int(a[0]) + len(a)
    ret = str(ret)
    a = ret
    cnt += 1
if a == ret:
    print("FA")
else:
    print("NFA")
