gandalfList = [1, 2, 3, 3, 4, 10]
sauronList = [1, 2, 2, 2, 3, 5, 10]
t = int(input())
for i in range(t):
    gandalfScore, sauronScore = 0, 0
    gandalfArmy = list(map(int, input().split()))
    sauronArmy = list(map(int, input().split()))
    for j in range(len(gandalfList)):
        gandalfScore += gandalfArmy[j] * gandalfList[j]
    for j in range(len(sauronList)):
        sauronScore += sauronArmy[j] * sauronList[j]
    print(f'Battle {i+1}: ', end='')
    if sauronScore < gandalfScore:
        print('Good triumphs over Evil')
    elif sauronScore > gandalfScore:
        print('Evil eradicates all trace of Good')
    else:
        print('No victor on this battle field')
