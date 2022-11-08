k, l = map(int, input().split())
st = "GOOD"
for i in range(2, l):
    if k % i == 0:
        st = "BAD " + str(i)
        break
print(st)
