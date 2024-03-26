word = input()
u = 0
l = 0
for x in word:
	if x.isupper():
		u += 1
	elif x.islower():
		l += 1
if u > l:
	word = word.upper()
else:
	word = word.lower()
print(word)
