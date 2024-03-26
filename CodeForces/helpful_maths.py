nums = input()
nums = nums.strip().split(sep = '+')
nums.sort()
line = ''
for x in nums:
	line += x + '+'
print(line[:-1])
