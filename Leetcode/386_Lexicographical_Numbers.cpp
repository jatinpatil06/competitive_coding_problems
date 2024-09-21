class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i = 1; i <= n; i++)
            ans.push_back(to_string(i));
        sort(ans.begin(), ans.end());
        vector <int> sorted_ans;
        for(auto i:ans)
            sorted_ans.push_back(stoi(i));
        return sorted_ans;
    }
};