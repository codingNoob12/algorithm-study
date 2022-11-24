pushedButtons = list(map(int, input().split()))
# sol 1)
money = 5000 - (500 * pushedButtons.count(1) + 800 * pushedButtons.count(2) + 1000 * pushedButtons.count(3))
# sol 2)
# for button in pushedButtons:
#     if button == 1:
#         money -= 500
#     elif button == 2:
#         money -= 800
#     elif button == 3:
#         money -= 1000
print(money)
