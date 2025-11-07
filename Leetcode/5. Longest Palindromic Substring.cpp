class Solution {
public:
    /*
        Brute Force Approach with TC = O(N ^ 3)

    bool isPalindrome(string &s, int l, int r){
        while(l <= r){
            if(s[l] != s[r])    return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string longest = "";
        int max_len = 0, n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    if(j - i + 1 > max_len){
                        max_len = j - i + 1;
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return longest;
    }
        An Better approach would be to use two pointers with TC = O(N ^ 2)
    */

    string findLongest(string &s, int l, int r){
        string longest = "";
        while((l >= 0 && r < s.length()) && s[l] == s[r]){
            longest = s.substr(l, r - l + 1);
            l--;
            r++;
        }
        return longest;
    }
    string longestPalindrome(string s){
        int max_len = 0, n = s.length();
        string longest = "";
        for(int i = 0; i < n; i++){
            string temp;
            temp = findLongest(s, i, i);
            if(temp.length() > max_len){
                longest = temp;
                max_len = max(max_len, (int)longest.length());
            } 
            temp = findLongest(s, i - 1, i);
            if(temp.length() > max_len){
                longest = temp;
                max_len = max(max_len, (int)longest.length());
            } 
        }
        return longest;
    }
};