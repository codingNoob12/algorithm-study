for a in range(2, 101):
    cube = a ** 3
    for b in range(2, a):
        for c in range(b+1, a):
            for d in range(c+1, a):
                triple = b ** 3 + c ** 3 + d ** 3
                if triple == cube:
                    print(f'Cube = {a}, Triple = ({b},{c},{d})')
