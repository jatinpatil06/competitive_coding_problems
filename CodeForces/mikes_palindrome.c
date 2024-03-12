#include<stdio.h>
#include<string.h>
int main()
{
	char st[30];
	scanf("%s", st);
	char copy[30];
	strcpy(copy, st);
	strrev(copy);
	int c = 0;
	for(int i = 0 ; i < strlen(st); i++)
	{
		if(st[i] != copy[i])
			c++;
	}
	if(c == 2)
		printf("YES");
	else if ((strlen(st) % 2 != 0) && c == 0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
