#include<iostream>
int* insertion_sort_asc(int a[], int n)
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
int* insertion_sort_desc(int a[], int n)
{
      for(int i= 1; i < n; i++)
      {
	    int key = a[i];
	    int j = i-1;
	    while(j >= 0 && key > a[j])
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
      int *res = new int[t];
      for(int i = 0; i < t; i++)
      {
	    int n;
	    int k;
	    scanf("%d%d", &n, &k);
	    int *a = new int[n];
	    int *b = new int[n];
	    for(int j = 0; j < n; j++)
		  scanf("%d", &a[j]);
	    for(int j = 0; j < n; j++)
		  scanf("%d", &b[j]);
	    insertion_sort_asc(a,n);
	    insertion_sort_desc(b,n);
	    /*
	    for(int j = 0, p = 0; j < n, p < k; j++)
	    {
		  int temp = a[j];
		  a[j] = b[j];
		  b[j] = temp;
		  k++;
	    }
	    */
	    int p =0;
	    while(p < k)
	    {
		  if(a[p] < b[p])
			a[p] = b[p];
		  p++;
	    }
	    int s =0;
	    for(int j = 0; j < n; j++)
		  s += a[j];
	    res[i] = s;
      }
      for(int i = 0; i < t; i++)
	    printf("%d\n", res[i]);
      return 0;
}
