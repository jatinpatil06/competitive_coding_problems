t = int(input())
old = []
new = []
for x in range(t):
	room = int(input())
	old.append(room)

for x in range(t):
	room= old[x]
	c = 0
	for x in range(1, (room % 10) + 1):
		no = 0
		for y in range(1, 5):
			no = (no * 10) + x
			#print(no)
			c += len(str(no))
			if(room == no):
				new.append(c)
				break

for x in new:
	print(x)
