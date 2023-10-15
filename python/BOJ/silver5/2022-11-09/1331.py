posList = []
mes = "Valid"
for i in range(36):
    pos = input()
    if len(posList) == 0:
        posList.append(pos)
        continue
    if pos in posList or abs(ord(posList[-1][0]) - ord(pos[0])) * abs(ord(posList[-1][1]) - ord(pos[1])) != 2:
        mes = "Invalid"
        break
    posList.append(pos)
if abs(ord(posList[0][0]) - ord(posList[-1][0])) * abs(ord(posList[0][1]) - ord(posList[-1][1])) != 2:
    mes = "Invalid"
print(mes)
