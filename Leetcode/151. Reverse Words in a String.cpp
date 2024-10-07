class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string reversed = "";
        while(ss >> word)
            reversed = word + " " + reversed;
        reversed.erase(reversed.size()-1);
        return reversed;
    }
};