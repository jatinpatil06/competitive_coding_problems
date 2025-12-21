#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0, n = arr.size();
        /*  Brute Force TC = O(N ^ 2)
            Generating all subarrays and finding the minimum in each
        for(int i = 0; i < n; i++){
            int min_num = arr[i];
            for(int j = i; j < n; j++){
                min_num = min(min_num, arr[j]);
                sum = (sum + min_num) % MOD;
            }
        }
            An optimal approach would be to take an element and find in how many subarrays is it a minimum? then multiply the element with that number and add to the sum
            This would result in a TC = O(N) & SC = O(3N)

            Important Note -
            Example [3, 1, 2, 1, 4]
            When values are equal, only ONE of them should "claim" the subarrays that include both.
            Using > in both: Neither claims the shared subarrays [1, 2, 1] (undercount)
            Using >= in one direction: The element in that direction claims all shared subarrays (correct count)
        */
        stack<int> st;
        vector<int> nse(n), pse(n);
        //finding the prev smaller element
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])    st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        //clearing the stack
        while(!st.empty())  st.pop();
        //finding the next smaller element
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])    st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            //in how many contiguous subarrays is this element mimimum?
            int start = i - pse[i], end = nse[i] - i;
            long long int min_subarrs = (start % MOD) * (end % MOD);
            sum = (sum + (min_subarrs * arr[i] )) % MOD; 
        }
        return sum;
    }
};