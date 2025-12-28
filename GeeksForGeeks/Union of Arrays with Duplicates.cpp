class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0, m = a.size(), n = b.size();
        vector<int> ans;
        while(i < m && j < n){
            if(a[i] == b[j]){
                int curr = a[i];
                ans.push_back(curr);
                while(i < m && a[i] == curr) i++;
                while(j < n && b[j] == curr) j++;
            }
            else if(a[i] < b[j]){
                int curr = a[i];
                ans.push_back(curr);
                while(i < m && a[i] == curr) i++;
            }   
            else{
                int curr = b[j];
                ans.push_back(curr);
                while(j < n && b[j] == curr) j++;
            }
        }
        while(i < m){
            int curr = a[i];
            ans.push_back(curr);
            while(i < m && a[i] == curr) i++;
        }
        while(j < n){
            int curr = b[j];
            ans.push_back(curr);
            while(j < n && b[j] == curr) j++;
        }
        return ans;
    }
};