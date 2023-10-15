numList = [int(input()) for _ in range(9)]
print(max(numList), numList.index(max(numList))+1, sep='\n')
