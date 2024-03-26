letters = set()
word = input()
for x in word:
	letters.add(x)
if len(letters) % 2 != 0:
	print('IGNORE HIM!')
else:
	print('CHAT WITH HER!')
