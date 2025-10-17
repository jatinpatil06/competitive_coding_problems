class Solution {
public:
    void generate(string s, int n, int idx, vector<string> &answers, map<int, vector<char>> &keys, string &digits){
        if(idx == n)   answers.push_back(s);
        else{
            for(char ch : keys[digits[idx] - '0'])  generate(s + ch, n, idx + 1, answers, keys, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> answers;
        map<int, vector<char>> keys;
        keys[2] = {'a', 'b', 'c'};
        keys[3] = {'d', 'e', 'f'};
        keys[4] = {'g', 'h', 'i'};
        keys[5] = {'j', 'k', 'l'};
        keys[6] = {'m', 'n', 'o'};
        keys[7] = {'p', 'q', 'r', 's'};
        keys[8] = {'t', 'u', 'v'};
        keys[9] = {'w', 'x', 'y', 'z'};
        generate("", digits.size(), 0, answers, keys, digits);
        return answers;
    }
};