class Solution {
  public:
    void generate_subsets(int sum, int idx, vector<int> &subset_sums, vector<int> &arr){
        if(idx == arr.size())   subset_sums.push_back(sum);
        else{
            //take this element
            generate_subsets(sum + arr[idx], idx + 1, subset_sums, arr);
            //skip this element
            generate_subsets(sum, idx + 1, subset_sums, arr);
        }
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> subset_sums;
        generate_subsets(0, 0, subset_sums, arr);
        return subset_sums;
    }
};