class Solution {
public:
    static bool customComparator(vector <int> &a, vector<int> &b){
        if(a[1] == b[1])    return a[0] < b[0];
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), customComparator);
        int count = 1;
        int last_end_time = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= last_end_time){
                count++;
                last_end_time = intervals[i][1];
            }    
        }
        return n - count;
    }
};