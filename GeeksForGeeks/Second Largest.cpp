class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        /*Better Approach
        int second_largest = -1, largest = arr[0];
        for(int i = 1; i < arr.size(); i++) largest = max(largest, arr[i]);
        for(int i = 0; i < arr.size(); i++) if(arr[i] != largest)   second_largest = max(second_largest, arr[i]);
        return second_largest;
        */
        int second_largest = -1, largest = -1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                second_largest = largest;
                largest = arr[i];
            }
            else if(arr[i] < largest && arr[i] > second_largest)    second_largest = arr[i];
        }
        return second_largest;
    }
};