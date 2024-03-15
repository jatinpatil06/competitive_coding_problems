#include<stdio.h>
int main()
{
	int n;
	printf("%d",n);
	int list[n];
	scanf("%d", &n);
	for(int x = 0; x < n; x++)
	{
		int a, b;
		int count = 0;
		scanf("%d%d", &a, &b);
		//for a horizontal cut
		if(a % 2 == 0)
		{
			int c = a / 2;
			int d = b * 2;
			if ((a * b == c * d) && ((a != d) || (c != b)))
				count ++;
		}
		//for a vertical cut
		if(b % 2 == 0)
		{
			int c = a * 2;
			int d = b / 2;
			if ((a * b == c * d) && ((a != d) || (c != b)))
				count ++;
		}
		if(count >= 1)
			list[x] = 1;
		else
			list[x] = 0;
	}
	for(int x = 0; x < n; x++)
	{
		if(list[x] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
