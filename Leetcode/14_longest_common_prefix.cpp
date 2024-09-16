class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commons = "";
        int j = 0;
        if(strs.empty() || strs[0].empty())
            return commons;
        while(true)
        {
            bool flag = true;
            if(j >= strs[0].size())      return commons;
            char token = strs[0][j];
    
            for(int i = 0; i < strs.size(); i++)
            {
                if(j>= strs[i].size() || strs[i][j] != token)
                    return commons;
            }
            commons += token;
            j +=1;
        }
        return commons;
    }
};