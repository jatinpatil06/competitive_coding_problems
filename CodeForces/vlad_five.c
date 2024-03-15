#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	char list[t];
	for(int i = 0; i < t; i++)
	{
		char s[5];
		scanf("%s", s);
		int x = 0;
		int ac = 0, bc = 0;
		while(s[x] != '\0')
		{
			if(s[x] == 'A')
				ac++;
			else if (s[x] == 'B')
				bc++;
			x++;
		}
		if(ac > bc)
			list[i] = 'A';
		else
			list[i] = 'B';
	}
	for(int i = 0; i < t; i++)
		printf("%c\n", list[i]);
	return 0;
}
