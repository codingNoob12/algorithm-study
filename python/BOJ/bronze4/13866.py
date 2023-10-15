skillLevels = list(map(int, input().split()))
skillLevels.sort()
diff = abs((skillLevels[0] + skillLevels[3]) - (skillLevels[1] + skillLevels[2]))
print(diff)
