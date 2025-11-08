class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meetings;
        for(int i = 0; i < start.size(); i++)   meetings.push_back({start[i], end[i]});
        sort(meetings.begin(), meetings.end(), [] (const pair<int, int> &a, const pair<int, int> &b){
            if(a.second == b.second)    return a.first < b.first;
            return a.second < b.second;
        });
        vector<pair<int, int>> non_overlapping_meets;
        non_overlapping_meets.push_back(meetings[0]);
        for(int i = 1; i < meetings.size(); i++){
            if(meetings[i].first > non_overlapping_meets.back().second)
                non_overlapping_meets.push_back(meetings[i]);
        }
        return non_overlapping_meets.size();
    }
};