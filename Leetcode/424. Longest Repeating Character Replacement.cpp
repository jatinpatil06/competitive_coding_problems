class Solution {
public:
    int characterReplacement(string s, int k) {
        //Applying the contribution technique
        int max_len = 0, n = s.size();
        for(char ch = 'A'; ch <= 'Z'; ch++){
            int l = 0, r = 0, count = 0;
            while(r < n){
                if(s[r] != ch)  count++;
                while(count > k){
                    if(s[l] != ch)  count--;
                    l++;
                }
                max_len = max(max_len, r - l + 1);
                r++;
            }
        }
        return max_len;
    }
};