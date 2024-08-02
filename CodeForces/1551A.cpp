#include<iostream>
int main()
{
      int t;
      scanf("%d", &t);
      int res[10000][2];
      //int **res = new int[t][2];
      for(int i = 0; i < t; i++)
      {
	    int n;
	    scanf("%d", &n);
	    if(n % 3 ==0)
	    {
		  res[i][0] = n / 3;
		  res[i][1] = n / 3;
	    }
	    else if (n % 3 == 1)
	    {
		  res[i][0] = (n / 3) + 1;
		  res[i][1] = n / 3;
	    }
	    else if(n % 3 == 2)
	    {
		  res[i][0] = n / 3;
		  res[i][1] = (n / 3) + 1;
	    }
      }
      for(int i = 0; i < t; i++)
	    printf("%d %d\n", res[i][0], res[i][1]);
      return 0;
}
