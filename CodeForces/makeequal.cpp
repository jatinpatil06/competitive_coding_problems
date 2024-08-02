#include<iostream>
int main()
{
      int t;
      scanf("%d", &t);
      int *res = new int[t];
      for(int i = 0; i < t; i++)
      {
	    int n;
	    scanf("%d", &n);
	    int *a = new int[n];
	    int s = 0;
	    for(int j = 0; j < n; j++)
	    {
		  scanf("%d", &a[j]);
		  s += a[j];
	    }
	    int lvl = s / n;
	    for(int j = n-1; j >= 0; j--)
	    {
		  if(a[j] > lvl)
		  {
			res[i] = 0;
			break;
		  }
		  else
		  {
			int diff = lvl - a[j];
			a[j] += diff;
			a[j-1] -= diff;
		  }
		  /*
		  else if (a[j] == lvl)
		  {
			//pass
		  }
		  else if(a[j] < lvl)
		  {
			int p = j-1;
			while(p >= 0 )
			{
			      if(a[j] == lvl)
				    break;
			      if(a[p] > lvl)
			      {
				    a[p]--;
				    a[j]++;
			      }
			      if(a[p] <= lvl)
				    p--;
			}
		  }
		  */
	    }

	    bool flag = true;
	    for(int q = 0; q < n; q++)
		  if(a[q] != lvl)
			flag = false;
	    if(flag == false)
		  res[i] = 0;
	    else
		  res[i] = 1;
	    delete(a);
      }
      for( int i = 0; i< t; i++)
      {
	    if(res[i] == 0)
		  printf("NO\n");
	    else
		  printf("YES\n");
      }
      return 0;
}
