#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int q;
    cin >> q;
    int flags = 0, count = 0, copy;
    while(q--)
    {
        int query, i;
        cin >> query;
        switch(query)
        {
            case 1 :   
                cin >> i; 
                if(flags & (1LL << i))    cout << 1 << "\n";
                else    cout << 0 << "\n";
                break;
            case 2 :
                cin >> i;
                flags = flags | (1LL << i);
                break;
            case 3 :
                cin >> i;
                flags = flags & (~(1LL << i));
                break;
            case 4 :
                cin >> i;
                flags = flags ^ (1LL << i);
                break;
            case 5 :
                count = 0;
                copy = flags;
                while(copy > 0)
                {
                    if(copy & 1LL)    count++;
                    copy >>= 1;
                }
                if(count == 60 )cout << 1 << "\n";
                else    cout << 0 << "\n";
                break;
            case 6 :
                if(flags > 0)   cout << "1\n";
                else    cout << 0 << "\n";
                break;
            case 7 :
                if(flags == 0)  cout << 1 << "\n";
                else    cout << 0 << "\n";
                break;
            case 8 :
                count = 0;
                copy = flags;
                while(copy > 0)
                {
                    if(copy & 1LL)    count++;
                    copy >>= 1;
                }
                cout << count << "\n";
                break;
            case 9 :
                cout << flags << "\n";
        }
    }
}