#include<stdio.h>
int main()
{
      int t;
      scanf("%d", &t);
      int *res = new int[t];
      for(int i = 0; i < t; i++)
      {
	    int n;
	    scanf("%d", &n);
	    char *a = new char[n];
	    scanf(" %s", a);
	    int c = 0;
	    for(int k = 0; k < n; k++)
	    {
		  if(a[k] == '*' && a[k+1] == '*')
			break;
		  if(a[k] == '@')
			c++;
	    }
	    res[i] = c;
      }
      for(int i = 0 ;i < t; i++)
	    printf("%d\n", res[i]);
      return 0;
}
