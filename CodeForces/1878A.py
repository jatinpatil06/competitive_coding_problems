t = int(input())
res =[]
for i in range(t):
	n, k = input().split()
	l = input().split()
	if k in l:
		res.append('YES')
	else:
		res.append("NO")
for x in res:
	print(x)
