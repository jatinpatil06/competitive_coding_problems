class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        string removed = "";
        while( i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n)  break;
            int startIdx = i;
            while(i < n && s[i] != ' ') i++;
            string word = s.substr(startIdx, i - startIdx);
            if(!removed.empty())    removed = word + ' ' + removed;
            else    removed = word;
        }
        return removed;
    }
};