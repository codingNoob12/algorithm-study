from datetime import timedelta
h, m = map(int, input().split())
res = timedelta(hours=h, minutes=m) - timedelta(minutes=45)
print(res.seconds // 3600, res.seconds // 60 % 60)
