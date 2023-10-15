from math import sqrt

def getDist(pos1, pos2):
    return sqrt((pos1[0] - pos2[0]) ** 2 + (pos1[1] - pos2[1]) ** 2)

nums = list(map(int, input().split()))
coordinates = [tuple(nums[i:i+2]) for i in range(0, len(nums), 2)]
A, B, C = coordinates
if ((B[1] - A[1]) * (C[0] - B[0])) == ((C[1] - B[1]) * (B[0] - A[0])):
    print(-1)
    exit(0)
distList = [getDist(A, B) + getDist(B, C), getDist(B, C) + getDist(C, A), getDist(C, A) + getDist(A, B)]
print(2 * (max(distList) - min(distList)))
