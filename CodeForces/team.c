#include<stdio.h>
int main()
{
	int n;
	int c = 0;
	scanf("%d", &n);
	int A[1000][3];
	for(int i = 0; i< n; i++)
	{
		for(int j = 0; j< 3; j++)
			scanf("%d", &A[i][j]);
		int x = A[i][0] + A[i][1] + A[i][2];
		if (x >= 2)
			c++;
	}
	printf("%d", c);
	return 0;
}