bool compareBySeconds(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_counts;
        for(auto num : nums)
            num_counts[num] += 1;
        vector<pair<int, int>> nums_vec;
        for(auto &elem : num_counts)
            nums_vec.push_back({elem.first, elem.second});
        sort(nums_vec.begin(), nums_vec.end(), compareBySeconds);
        vector<int> k_most_freq;
        for(int i = 0; i < k; i++)
            k_most_freq.push_back(nums_vec[i].first);
        return k_most_freq;
    }
};