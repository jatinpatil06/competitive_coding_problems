class Solution {
public:
    vector<int> solve(string s)
    {
        vector<int>ans;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                //we can split or not split
                //right now we will split
                vector<int>left = solve(s.substr(0,i));
                vector<int>right = solve(s.substr(i+1));
                for(auto x : left)
                {
                    for(auto y : right)
                    {
                        if(s[i] == '+')
                            ans.push_back(x + y);
                        else if(s[i] == '-')
                            ans.push_back(x - y);
                        else if(s[i] == '*')
                            ans.push_back(x * y);
                    }
                }
            }
        }
        if(ans.empty())
            ans.push_back(stoi(s));
        return ans;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};