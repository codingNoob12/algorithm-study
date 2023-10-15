# classes = []
# for _ in range(int(input())):
#     classes.append(list(map(int, input().split())))
# cntList = []
# for student in classes:
#     cnt = 0
#     flag = False
#     for comparison in classes:
#         if student == comparison:
#             continue
#         for i in range(len(student)):
#             if student[i] == comparison[i]:
#                 cnt += 1
#                 break
#     cntList.append(cnt)
# print(cntList.index(max(cntList)) + 1)

n = int(input())
classes = [list(map(int, input().split())) for _ in range(n)]
cnt_list = [0] * n
for i, student in enumerate(classes):
    for comparison in classes[:i] + classes[i+1:]:
        for j in range(len(student)):
            if student[j] == comparison[j]:
                cnt_list[i] += 1
                break
print(cnt_list.index(max(cnt_list)) + 1)
