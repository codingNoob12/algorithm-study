# from itertools import combinations
# for _ in range(int(input())):
#     CLOTHES = {}
#     for _ in range(int(input())):
#         cloth, category = input().split()
#         if category in CLOTHES:
#             CLOTHES[category].append(cloth)
#         else:
#             CLOTHES[category] = [cloth]
#     ans = 0
#     for i in range(1, len(CLOTHES.keys()) + 1):
#         for categories in combinations(CLOTHES.keys(), i):
#             cnt = 1
#             for category in categories:
#                 cnt *= len(CLOTHES[category])
#             ans += cnt
#     print(ans)

for _ in range(int(input())):
    CLOTHES = {}
    for _ in range(int(input())):
        cloth, category = input().split()
        if category in CLOTHES:
            CLOTHES[category] += 1
        else:
            CLOTHES[category] = 1
    ans = 1
    for count in CLOTHES.values():
        ans *= (count + 1)
    # 모든 경우의 수 (어떤 옷도 입지 않은 경우 포함) => 해당 경우 제외
    ans -= 1
    print(ans)
