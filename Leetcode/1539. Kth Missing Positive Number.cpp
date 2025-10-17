class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*Brute Force - O(n) approach
        vector<int> missing;
        int j = 0, g = 1;
        while(missing.size() != k){
            if(j < arr.size() && arr[j] == g)   j++;
            else    missing.push_back(g);
            g++;
        }
        return missing[k - 1];
        */
    }
};