import sys
from math import *

def fast_input():
    return sys.stdin.readline().rstrip()

def init(start, end, node):
    if start == end:
        segment_tree[node] = nums[start]
        return segment_tree[node]
    mid = (start + end) // 2
    segment_tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1)
    return segment_tree[node]

def get_sum(start, end, node, left, right):
    if left > end or right < start:
        return 0
    if start >= left and end <= right:
        return segment_tree[node]
    mid = (start + end) // 2
    return get_sum(start, mid, node * 2, left, right) + get_sum(mid + 1, end, node * 2 + 1, left, right)

def update(start, end, node, index, diff):
    if start > index or end < index:
        return
    segment_tree[node] += diff
    if start == end:
        return
    mid = (start + end) // 2
    update(start, mid, node * 2, index, diff)
    update(mid + 1, end, node * 2 + 1, index, diff)

N, M, K = map(int, fast_input().split())
nums = [int(fast_input()) for _ in range(N)]
segment_tree = [0] * (2 ** (ceil(log2(N)) + 1))
init(0, N - 1, 1)

for _ in range(M + K):
    a, b, c = map(int, fast_input().split())
    if a == 1:
        diff = c - nums[b - 1]
        nums[b - 1] = c
        update(0, N - 1, 1, b - 1, diff)
    else:
        print(get_sum(0, N - 1, 1, b - 1, c - 1))
