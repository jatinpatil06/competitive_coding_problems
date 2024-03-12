#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int x = 0;
	scanf("%d",&n);
	char s[n][3];
	for(int i = 0; i< n; i++)
	{
		scanf("%s", s[i]);
		if((strcmp(s[i], "++X") == 0) || (strcmp(s[i], "X++") == 0))
			x++;
		else if((strcmp(s[i], "--X") == 0) || (strcmp(s[i], "X--") == 0))
			x--;
	}
	printf("%d", x);
	return 0;
}