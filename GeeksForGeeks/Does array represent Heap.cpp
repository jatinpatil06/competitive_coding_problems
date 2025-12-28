
class Solution {
  public:
    bool check(int arr[], int i, int n){
        if(i >= n)  return true;
        int left = 2 * i + 1, right = 2 * i + 2;
        if(arr[left] > arr[i] || arr[right] > arr[i])  return false;
        return (true && check(arr, left, n) && check(arr, right, n));
    }
    bool isMaxHeap(int arr[], int n) {
        return check(arr, 0, n);
    }
};