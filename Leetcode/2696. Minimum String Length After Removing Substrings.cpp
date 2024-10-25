class Solution {
public:
    int minLength(string s) {
        bool flag = true;
        while(flag)
        {
            flag = false;
            string new_str = "";
            for(int i = 0; i < s.length(); i++)
            {
                if(s.substr(i,2) != "AB" && s.substr(i,2) != "CD")
                    new_str += s[i];
                else
                {
                    i += 1;
                    flag = true;
                }
                //cout << new_str << endl;
            }
            s = new_str;
        }
        return s.length();
    }
};