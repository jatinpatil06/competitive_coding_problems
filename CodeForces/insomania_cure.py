k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
nl =[]
c = 0
if k == 1:
	print(d)
else:
	for x in range(1, d+1):
		if x % k == 0 or x % l == 0 or x % m == 0 or x % n == 0:
			c += 1
	print(c)
