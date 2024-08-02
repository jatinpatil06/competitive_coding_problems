#include<iostream>
#include<cmath>
int* insertion_sort(int a[], int n)
{
      for(int i= 1; i < n; i++)
      {
	    int key = a[i];
	    int j = i-1;
	    while(j >= 0 && key < a[j])
	    {
		  a[j+1] = a[j];
		  j--;
	    }
	    a[j+1] = key;
      }
      return a;
}
int main()
{
      int t;
      scanf("%d", &t);
      int res[1000];
      for(int i = 0; i < t; i++)
      {
	    int n;
	    scanf("%d", &n);
	    int *a = new int[n];
	    for(int j = 0; j < n; j++)
		  scanf("%d", &a[j]);
	    insertion_sort(a,n);
	    int k = 0;
	    for(; k < n; k++)
	    {
		  if(a[k] >= 0)
			break;
	    }
	    for(int p = 0; p < k; p++)
		  a[p] = abs(a[p]);
	    int s = 0;
	    for(int j = 0; j < n; j++)
		  s += a[j];
	    res[i] = s;

      }
      for(int i = 0; i < t; i++)
	    printf("%d\n", res[i]);
      return 0;
}
