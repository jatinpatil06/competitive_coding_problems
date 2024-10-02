class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        while(ss >> word)
            word = word;
        return word.length();
    }
};