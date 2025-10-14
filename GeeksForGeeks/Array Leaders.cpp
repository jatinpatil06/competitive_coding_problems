class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> leaders;
        int maximum = INT_MIN;
        for(int i = n - 1; i >= 0 ; i--){
            if(arr[i] >= maximum)   leaders.insert(leaders.begin(), arr[i]);
            maximum = max(maximum, arr[i]);
        }
        return leaders;
    }
};