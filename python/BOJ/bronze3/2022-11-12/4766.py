pre, flag = 0, False
while True:
    celsius = float(input())
    if celsius == 999:
        break
    if flag:
        print('{:.2f}'.format(celsius - pre))
    pre = celsius
    flag = True
