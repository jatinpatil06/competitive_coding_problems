#include<iostream>
using namespace std;
int main()
{
      int t;
      cin >> t;
      for(int i = 0; i < t; i++)
      {
	    int a, b, c;
	    cin >> a >> b >> c;
	    int n = 0;
	    n += a;
	    a = 0;
	    cout << a<<b<<c;
	    n += b / 3;
	    b = b % 3;
	    cout << a<<b<<c;

	    if(b != 0)
	    {
		  n += 1;
		  b = 0;
		  c -= (3 - b);
		  //cout << a<<b<<c;
	    }

	    if(c < 0)
		  cout << "NO";
	    n += c / 3;
	    c = c % 3;

	    if(c != 0)
	    {
		  n += 1;
		  c -= (c % 3);
	    }

	    if(a == 0 && b == 0 && c ==0)
		  cout << n;
	    else
		  cout << -1;
      }
      return 0;
}
