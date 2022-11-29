# import string
# def baseRadixConversion(n, b):
#     exponential = 0
#     res = 0
#     for ch in n[::-1]:
#         if ch in string.digits:
#             res += (ord(ch) - 48) * b ** exponential
#         else:
#             res += (ord(ch) - 55) * b ** exponential
#         exponential += 1
#     return res
#
# n, b = input().split()
# print(baseRadixConversion(n, int(b)))

n, b = input().split()
print(int(n, int(b)))
