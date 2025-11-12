class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n), nge(2 * n);
        for(int i = 0; i < n; i++)  nums.push_back(nums[i]);
        stack<int> st;
        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i])   st.pop();
            if(st.empty())  nge[i] = -1;
            else    nge[i] = st.top();
            st.push(nums[i]);
        }
        for(int i = 0; i < n; i++)  answer[i] = nge[i];
        return answer;
    }
};