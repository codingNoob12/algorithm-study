from itertools import combinations

v = [0, 1, 2, 3]

# v에서 2개 뽑아 나열한 결과 출력
for i in combinations(v, 2):
    print(i)
