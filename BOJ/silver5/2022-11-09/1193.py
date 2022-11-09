n = int(input())
cnt = 0
k = 1
while cnt < n:
    cnt += k
    k += 1
if k % 2 == 0:
    a = 1 + cnt - n
    b = k - a
else:
    b = 1 + cnt - n
    a = k - b
print(str(a) + "/" + str(b))
