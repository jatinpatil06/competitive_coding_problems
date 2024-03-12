#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d", &n);
	char s[n][1000];	//to store the names initially
	
	for(int i = 0; i < n; i++)
	{
		char temp[1000];
		scanf("%s", temp);
		strcpy(s[i], temp);
	}
	
	char list[n][1000];	//to keep a copy of the scanned names
	int k = 0;
	
	for(int i = 0; i < n; i++)
	{
		char temp[1000];
		strcpy(temp, s[i]);
		int flag = 0;
		for( int j = 0; list[j][0] != '\0'; j++)
		{
			if(strcmp(list[j], temp) == 0)
			{
				printf("YES\n");
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			strcpy(list[k++], temp);
			printf("NO\n");
		}
	}
	return 0;
}
