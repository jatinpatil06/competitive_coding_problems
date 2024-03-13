def palindrome(time):
	if(time == time[::-1]):
		return True
	else:
		return False
		
time = input()
c = 0

if(palindrome(time)):
	print(c)
else:
	time = time.split(sep = ':')
	hour = int(time[0])
	mins = int(time[1])
	while(True):
		mins += 1
		c += 1
		if(mins == 60):
			hour += 1
			mins = 0
		if(hour == 24):
			hour = 0
		#print(time)
		time = str(hour).zfill(2) + ":" + str(mins).zfill(2)
		if(palindrome(time)):
			print(c)
			break
