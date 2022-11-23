s1, s2 = map(int, input().split())
for _ in range(s1):
    answer, correctAnswer = map(int, input().split())
    if answer != correctAnswer:
        print('Wrong Answer')
        exit(0)
for _ in range(s2):
    answer, correctAnswer = map(int, input().split())
    if answer != correctAnswer:
        print('Why Wrong!!!')
        exit(0)
print('Accepted')
