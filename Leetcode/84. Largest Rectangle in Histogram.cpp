class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0, n = heights.size();
        /*  Brute Force Solution with TC = O(N ^ 2)
        for(int i = 0; i < n; i++){
            int cur_height = heights[i];
            //find the prev smaller height
            int j = i;
            while(j >=0 && heights[j] >= cur_height)    j--;
            int left = j;
            j = i;
            while(j < n && heights[j] >= cur_height)    j++;
            int right = j;
            area = max(area, cur_height * (right - left - 1));
        }
            An Optimal approach would be to use monotonic stacks
        */
        //we will store the indices of the next and prev smaller elements
        vector<int> pse(n), nse(n);
        stack<int> st;
        //prev smaller element
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())  st.pop();
        //next smaller element
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])   st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            int cur_height = heights[i];
            int left = pse[i];
            int right = nse[i];
            area = max(area, cur_height * (right - left - 1));
        }
        return area;
    }
};