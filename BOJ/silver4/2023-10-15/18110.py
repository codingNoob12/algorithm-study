import sys

def round(num):
    return int(num) + (1 if num - int(num) >= 0.5 else 0)

def fast_input():
    return sys.stdin.readline().rstrip()

levels = [int(fast_input()) for _ in range(int(fast_input()))]
if len(levels) == 0:
    print(0)
else:
    levels.sort()
    unit = round(len(levels) * 0.15)
    trimmed_levels = levels[unit:-unit] if unit != 0 else levels
    trimmed_mean = sum(trimmed_levels) / len(trimmed_levels)
    print(round(trimmed_mean))
