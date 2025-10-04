#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {1, 2, 2, 3, 3, 3, 7, 11};
    int low = 0, high = 7;
    int target = 10;
    int answer = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] >= target ? 1 : 0)
        {
            answer = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << answer;
    return 0;
}