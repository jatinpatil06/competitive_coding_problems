#include<iostream>
using namespace std;
int main()
{
	int cost, money, n;
	cin >> cost >> money >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += i * cost;
	if (money < sum)
		cout << abs(sum - money);
	else
		cout << 0 ;
	return 0;
}
