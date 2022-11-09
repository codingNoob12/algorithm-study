cnt = 0
for i in range(1, 6):
    name = input()
    if name.__contains__('FBI'):
        cnt += 1
        print(i, end=' ')
if cnt == 0:
    print('HE GOT AWAY!')
