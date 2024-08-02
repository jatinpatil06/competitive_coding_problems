#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int res[10000];
	int n;
	int days[150000];
	int s;
	for(int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
			scanf("%d", &days[j]);
		int min = days[n - 1];
		for(int j = n -2; j >= 0; j--)
		{
			if(days[j] > min)
				res[i] += 1;
			if(days[j] < min)
				min = days[j];
		}
	}
	for(int i = 0; i < t; i++)
		printf("%d\n", res[i]);
	return 0;
}
