#include<iostream>
using namespace std;
int main()
{
      int n;
      cin >> n;
      int score[1000];
      for(int i = 0; i < n; i++)
	    cin >> score[i];
      int min = score[0];
      int max = score[0];
      int amazing = 0;
      for(int i = 0; i < n; i++)
      {
	    if(score[i] > max)
	    {
		  max = score[i];
		  amazing++;
	    }
	    else if(score[i] < min)
	    {
		  min = score[i];
		  amazing++;
	    }
      }
      cout << amazing;
      return 0;
}
