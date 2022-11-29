dishes = input()
preDish = None
height = 0
for dish in dishes:
    if preDish == dish:
        height += 5
    else:
        height += 10
    preDish = dish
print(height)
