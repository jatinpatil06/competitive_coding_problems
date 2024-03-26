#include<iostream>
using namespace std;
int main()
{
      int k, r;
      cin >> k >> r;
      int n = 0;
      int sum = 0;
      while(true)
      {
	    sum += k;
	    n++;
	    if(sum % 10 == 0)
		  break;
	    else if (sum % 10 == r)
		  break;
      }
      cout << n;
      return 0;
}
