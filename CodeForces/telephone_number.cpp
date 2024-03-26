#include<iostream>
#include<cstring>
using namespace std;
int main()
{
      int t;
      cin >> t;
      char res[100][4];
      for(int x = 0; x < t; x++)
      {
	    int n;
	    cin >> n;
	    char s[n];
	    for(int i = 0; i < n; i++)
		  cin >> s[i];
	    int i =0;
	    while(i < n && (s[i] != '8'))
		  i++;
	    char new_str[100] = "";
	    int q = 0;
	    for(; i < n; i++)
		  new_str[q++] = s[i];
	    new_str[q] = '\0';

	    if(strlen(new_str) < 11)
		  strcpy(res[x], "NO");
	    else
		  strcpy(res[x], "YES");
	    //cout << res[x] << " ";
      }
      for(int i = 0; i < t; i++)
	    cout << res[i] << "\n";
      return 0;
}
