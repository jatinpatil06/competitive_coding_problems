#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int X[101];
	int Z[101];
	int res[101];
	int p;
	int q;
	cin >> p;
	for(int i = 1; i <= p; i++)
	{
		cin >> X[i];
		res[X[i]] = 1;
	}
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cin >> Z[i];
		res[Z[i]] = 1;
	}
	int flag = 0;
	for(int i = 1; i <= n; i++)
	{
		if(res[i] != 1)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";	
	return 0;
}
