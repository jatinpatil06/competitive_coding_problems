class Solution {
  public:
    int largest(vector<int> &arr) {
        int max_elem = arr[0];
        for(int i = 1; i < arr.size(); i++) max_elem = max(max_elem, arr[i]);
        return max_elem;
    }
};
