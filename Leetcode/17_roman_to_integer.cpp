class Solution {
public:
    int romanToInt(string s) {
        map <char, int> vals;
        vals['I'] = 1;
        vals ['V'] = 5;
        vals['X'] = 10;
        vals['L'] = 50;
        vals['C'] = 100;
        vals['D'] = 500;
        vals['M'] = 1000;

        int sum = 0;
        for(int i = 0; i < s.length();)
        {
            if(vals[s[i]] < vals[s[i+1]])
            {
                sum += vals[s[i+1]] - vals[s[i]];
                i += 2;
            }
            else
            {
                sum += vals[s[i]];
                i += 1;
            }
        }
        return sum;
    }
};