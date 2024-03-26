#include<iostream>
using namespace std;
int main()
{
      int t;
      cin >> t;
      int res[t] = {0};
      for(int i = 0; i < t; i++)
      {
	    int n;
	    cin >> n;
	    int list[10];
	    for(int j = 0; j < n; j++)
		  cin >> list[j];
	    int min = list[0];
	    int minpos = 0;
	    for(int j = 0; j < n; j++)
		  if(list[j] < min)
		  {
			min = list[j];
			minpos = j;
		  }
	    list[minpos] += 1;
	    int product = 1;
	    for(int j = 0; j < n; j++)
		  product *= list[j];
	    res[i] = product;
      }
      for(int j = 0; j < t; j++)
		  cout << res[j] << endl;
      return 0;
}
