class Solution {
  public:
    void generate(string s, int n, vector<string> &answers){
        if(s.size() == n)   answers.push_back(s);
        else{
            generate(s + "0", n, answers);
            generate(s + "1", n, answers);
        }
    }
    vector<string> binstr(int n) {
        vector<string> answers;
        generate("", n, answers);
        return answers;
    }
};