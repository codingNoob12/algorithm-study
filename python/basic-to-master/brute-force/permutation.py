from itertools import permutations

v = [0, 1, 2, 3]

# v에서 4개의 원소를 뽑아 나열한 모든 결과 출력
for i in permutations(v, 4):
    print(i)
