caseNum = 1
while True:
    n = int(input())
    if n == 0:
        break
    n1 = 3 * n
    n2 = n1 // 2 if n % 2 == 0 else (n1 + 1) // 2
    n3 = 3 * n2
    n4 = n3 // 9
    oddEven = 'odd' if n % 2 == 1 else 'even'
    print(f'{caseNum}. {oddEven} {n4}')
    caseNum += 1
