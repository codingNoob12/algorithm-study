n = int(input())
t = int(input())
start = n // 100 * 100
end = (n // 100 + 1) * 100
res = 0
for i in range(start, end):
    if i % t == 0:
        res = i
        break
print(str(res)[-2:])
