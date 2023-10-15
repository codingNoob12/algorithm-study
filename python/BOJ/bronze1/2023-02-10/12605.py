for i in range(1, int(input()) + 1):
    words = list(reversed(input().split()))
    print(f'Case #{i}:', *words)
