
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        /*  Brute Force Approach with TC = O(N*q) 
            We have to manually check for each element, we cannot do this for the entire array in linear time.*/
        int n = arr.size(), q = indices.size();
        vector<int> nges_count(q);
        for(int i = 0; i < q; i++){
            int count = 0;
            for(int j = indices[i] + 1; j < n; j++){
                if(arr[j] > arr[indices[i]]) count++;
            }
            nges_count[i] = count;
        }
        return nges_count;
        
    }
};