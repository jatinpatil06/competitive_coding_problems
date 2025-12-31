class Solution {
  public:
    static bool customComparator(vector<int> &a, vector<int> &b){
        if(a[1] == b[1])    return a[0] < b[0];
        return a[1] < b[1];
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>> intervals;
        int n = start.size();
        for(int i = 0; i < n; i++)  intervals.push_back({start[i], end[i]});
        sort(intervals.begin(), intervals.end(), customComparator);
        int count = 1, lastEndTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(lastEndTime < intervals[i][0]){
                count++;
                lastEndTime = intervals[i][1];
            }   
        }
        return count;
    }
};