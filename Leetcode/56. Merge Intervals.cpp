class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0])    return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= merged_intervals.back()[1])   
                merged_intervals.back()[1] = max(merged_intervals.back()[1], intervals[i][1]);
            else    merged_intervals.push_back(intervals[i]);
        }
        return merged_intervals;
    }
};