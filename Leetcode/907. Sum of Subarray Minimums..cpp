#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();

        /* Brute Force Approach with TC = O(N ^ 2)
        for(int i = 0; i < n; i++){
            int min_elem = arr[i];
            for(int j = i; j < n; j++){
                min_elem = min(min_elem, arr[j]);
                sum += min_elem;
            }
        }
        */

        //Find the next smallest and previous smallest elements
        vector<int> pse(n), nse(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty())  pse[i] = -1;
            else    pse[i] = st.top();
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty())  nse[i] = n;
            else    nse[i] = st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int l, r;
            l = i - pse[i];
            r = nse[i] - i;
            sum = (sum + (1LL * l * r) * arr[i]) % MOD;
        }
        return sum % MOD;
    }
};