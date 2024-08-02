#include<iostream>
int main()
{
	int n;
	scanf("%d", &n);
	int A[100000];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int max = 1;
	int c = 1;
	for(int i = 0; i < n - 1;i++)
	{
		if(A[i + 1] > A[i])
			c++;
		else
		{
			if(c > max)
				max = c;
			c = 1;
		}
	}
	if(c > max)
		max  = c;
	printf("%d", max);

	return 0;
}
