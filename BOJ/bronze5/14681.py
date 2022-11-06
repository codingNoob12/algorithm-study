x = int(input())
y = int(input())
axis = 0
if x > 0:
    axis = 1 if y > 0 else 4
else:
    axis = 2 if y > 0 else 3
print(axis)
