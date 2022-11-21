posList = ["small", None, None, "big"]
for shuffle in input():
    if shuffle == 'A':
        posList[0], posList[1] = posList[1], posList[0]
    elif shuffle == 'B':
        posList[0], posList[2] = posList[2], posList[0]
    elif shuffle == 'C':
        posList[0], posList[3] = posList[3], posList[0]
    elif shuffle == 'D':
        posList[1], posList[2] = posList[2], posList[1]
    elif shuffle == 'E':
        posList[1], posList[3] = posList[3], posList[1]
    else:
        posList[2], posList[3] = posList[3], posList[2]
print(posList.index('small') + 1, posList.index('big') + 1, sep='\n')
