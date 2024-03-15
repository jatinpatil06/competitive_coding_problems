#include<stdio.h>
int main()
{
	int n;
	int res[100000] = {0};
	scanf("%d", &n);
	for(int x = 0 ; x < n; x++)
	{
		int temp = 0;
		int c = 0;
		int l;
		scanf("%d", &l);
		char s[15];
		scanf("%s", s);
		
		int i = 0;
		for(; i < l ; i++)
			if(s[i] == 'B')
			{
				temp = 1;
				c = temp;
				break;
			}
			
		for(int j = i + 1; j < l; j++)
		{
			if(s[j] == 'B')
			{
				temp++;
				c = temp;
			}
			else
				temp++;
		}
		res[x] = c;
	}
	for( int x = 0 ; x < n; x++)
		printf("%d\n", res[x]);
	return 0;
}
