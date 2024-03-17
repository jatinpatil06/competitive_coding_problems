#include<iostream>
#include<cmath>
using namespace std;
void insertion_sort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while(key > arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
int main()
{
	int t;
	cin >> t;
	int res[501];
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int arr[101];
		for(int x = 0; x < n; x++)
			cin >> arr[x];
		insertion_sort(arr, n);
		int beaut = 0;
		for(int i = 1; i < n; i++)
			beaut += abs(arr[i] - arr[i-1]); 
		res[i] = beaut;
	}
	for(int i = 0; i < t; i++)
		cout << res[i] << "\n";
	return 0;
}
