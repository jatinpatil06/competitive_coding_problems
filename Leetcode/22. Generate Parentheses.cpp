class Solution {
public:
    /*
    Brute Force Approach
    void generate(string s, int n, int i, vector<string> &answers){
        if(i < 0)   return;
        if(s.length() == n){
            if(i == 0) answers.push_back(s);
        }
        else{
            generate(s + "(", n, i + 1, answers);
            generate(s + ")", n, i - 1, answers);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answers;
        generate("", 2*n, 0, answers);
        return answers;
    }
    */
    //Optimal Force Approach
    void generate(string s, int open, int close, int n, vector<string> &answers){
        if(s.length() == 2 * n)   answers.push_back(s);
        if(open < n)    generate(s + "(", open + 1, close, n, answers);
        if(close < open)    generate(s + ")", open, close + 1, n, answers);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answers;
        generate("", 0, 0, n, answers);
        return answers;
    }
};