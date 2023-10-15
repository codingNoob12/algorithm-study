tc = int(input())
for _ in range(tc):
    legs, chickens = map(int, input().split())
    t = legs - chickens
    u = chickens - t
    print(u, t)
