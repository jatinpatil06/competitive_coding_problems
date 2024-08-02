#include<iostream>
int main()
{
	int t;
	scanf("%d", &t);
	int *res = new int[t];
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int b[26];
		for(int j = 0; j < 26; j++)
			b[j] = 0;
		char *A = new char[n];
		scanf("%s", A);
		for(int j = 0; j < n; j++)
		{
			if(b[(int)(A[j] - 65)] == 0)
				b[(int)(A[j] - 65)] += 2;
			else
				b[(int)(A[j] - 65)] += 1;
		}
		int s = 0;
		for(int j = 0; j < 26; j++)
			s += b[j];
		res[i] = s;
	}
	for(int i = 0; i < t; i++)
		printf("%d\n", res[i]);
	return 0;
}
