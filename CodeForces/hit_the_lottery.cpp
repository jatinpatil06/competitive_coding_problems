#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int c = 0;
	//1, 5, 10, 20 ,100 dollar bills
	while(n != 0)
	{
		int rem = 0;
		int quo;
		if(n >= 100)
		{
			rem = n % 100;
			quo = n / 100;
			n = n - (100 * quo);
		}
		else if (n >= 20)
		{
			rem = n  % 20;
			quo = n / 20;
			n = n - (20 * quo);
		}
		else if (n >= 10)
		{
			rem = n % 10;
			quo = n / 10;
			n = n - (10 * quo);
		}
		else if (n >= 5)
		{
			rem = n % 5;
			quo = n / 5;
			n = n - (5 * quo);
		}
		else if (n >= 1)
		{
			rem = n % 1;
			quo = n / 1;
			n = n - (1 * quo);
		}
		c += quo;
	}
	cout << c;
	return 0;
}
