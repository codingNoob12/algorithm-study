# sol 1) Comprehension
# import sys
# input = sys.stdin.readline
#
# N, M = map(int, input().rstrip().split())
#
# # 딕셔너리 컴프리헨션으로 주소와 비밀번호를 입력받음
# dic = {address: password for _ in range(N) for address, password in [input().rstrip().split()]}
# # for address, password in dic.items():
# #     print(address, password)
#
# # 컴프리헨션으로 답을 리스트에 미리 담아버림
# res = [dic[address] for _ in range(M) for address in [input().rstrip()]]
# print(*res, sep='\n')

# sol 2)
import sys
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
dic = {}
for _ in range(N):
    address, password = input().rstrip().split()
    dic[address] = password
for _ in range(M):
    address = input().rstrip()
    print(dic[address])
