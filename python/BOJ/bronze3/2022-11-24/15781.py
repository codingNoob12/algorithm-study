n, m = map(int, input().split())
helmetDefenses = list(map(int, input().split()))
vestDefenses = list(map(int, input().split()))
print(max(helmetDefenses) + max(vestDefenses))
