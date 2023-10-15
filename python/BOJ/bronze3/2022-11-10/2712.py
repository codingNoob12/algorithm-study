t = int(input())
for i in range(t):
    val, unit = input().split()
    val = float(val)
    if unit == 'kg':
        print('{:0.4f} {}'.format(val * 2.2046, 'lb'))
    elif unit == 'lb':
        print('{:0.4f} {}'.format(val * 0.4536, 'kg'))
    elif unit == 'l':
        print('{:0.4f} {}'.format(val * 0.2642, 'g'))
    elif unit == 'g':
        print('{:0.4f} {}'.format(val * 3.7854, 'l'))
