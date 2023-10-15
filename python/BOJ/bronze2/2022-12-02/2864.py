a, b = input().split()
minVal = int(a.replace('6', '5')) + int(b.replace('6', '5'))
maxVal = int(a.replace('5', '6')) + int(b.replace('5', '6'))
print(minVal, maxVal)
