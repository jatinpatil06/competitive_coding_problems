class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_elem = -1;
        max_elem = max(max_elem, arr[arr.size() - 1]);
        arr[arr.size() - 1] = -1;
        for(int i = arr.size() - 2; i >= 0; i--)
        {
            int t = arr[i];
            arr[i] = max_elem;
            max_elem = max(max_elem, t);
        }
        return arr;
    }
};