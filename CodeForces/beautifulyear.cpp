#include<iostream>
#include<string>
using namespace std;
int main()
{
      int year;
      cin >> year;
      while(true)
      {
	    year++;
	    int year_cpy = year;
	    int yrarr[4] = {0};
	    int n = 3;
	    while(year_cpy != 0)
	    {
		  int r = year_cpy % 10;
		  yrarr[n--] = r;
		  year_cpy /= 10;
	    }

	    //char new[4] = to_string(year);
	    int bucket[10] = {0};
	    int flag = 0;
	    for(int i = 0; i < 4; i++)
	    {
		  bucket[yrarr[i]] += 1;
		  if(bucket[yrarr[i]] > 1)
		  {
			flag = 1;
			break;
		  }
	    }
	    if(flag == 0)
	    {
		  cout << year;
		  break;
	    }
      }
      return 0;
}
