class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals(n+1);
        for(int i = 0; i <= n; i++)
        {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            intervals[i] = {left, right};
        }
        sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        int i = 0;
        int end = 0;
        int taps = 0;
        while(end < n)
        {
            int farthest = end;
            while(i <= n && intervals[i].first <= end)
            {
                farthest = max(farthest, intervals[i].second);
                i++;
            }
            if(farthest == end)
                return -1;
            taps ++;
            end = farthest;
        }
        return taps;
    }
};