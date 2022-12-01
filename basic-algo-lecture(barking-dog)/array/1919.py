st1, st2 = input(), input()
st1CntDict, st2CntDict = {}, {}
for ch in st1:
    if ch in st1CntDict.keys():
        st1CntDict[ch] += 1
    else:
        st1CntDict[ch] = 1
for ch in st2:
    if ch in st2CntDict.keys():
        st2CntDict[ch] += 1
    else:
        st2CntDict[ch] = 1
intersections = set.intersection(set(st1CntDict.keys()), set(st2CntDict.keys()))
cnt = 0
for k1 in st1CntDict.keys():
    if k1 not in intersections:
        cnt += st1CntDict[k1]
    else:
        cnt += abs(st1CntDict[k1] - st2CntDict[k1])
for k2 in st2CntDict.keys():
    if k2 not in intersections:
        cnt += st2CntDict[k2]
print(cnt)
