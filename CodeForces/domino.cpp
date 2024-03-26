#include<iostream>
using namespace std;
int main()
{
	int m, n;
	int c = 0;
	cin >> m >> n;
	int A[m][n];
	//making the matrix empty
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			A[i][j] = -1;
			
	//filling the matrix with dominos
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((A[i][j] == -1) && (A[i][j+1] == -1))
			{
				A[i][j] = 1;
				A[i][j+1] = 1;
				c++;
			}
			if((A[i][j] == -1) && (A[i+1][j] == -1))
			{
				A[i][j] = 1;
				A[i+1][j] = 1;
				c++;
			}
		}
	}
	cout << c;
	return 0;
}
/*
	 * cout << "Matrix\n";
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
	*/
