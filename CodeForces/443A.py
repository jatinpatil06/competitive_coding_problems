line = input()
sset = set(line[1:-1].split(sep = ', '))
if(line == '{}'):
      print(0)
else:
      print(len(sset))
