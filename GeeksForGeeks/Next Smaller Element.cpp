class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        stack<int> st;
        vector<int> nse(arr.size());
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() >= arr[i])  st.pop();
            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};