class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        int n = heights.size();
        stack<int> st;
        vector<int> prev(n, 0);
        vector<int> next(n, 0);
        for(int i = n - 1; i >= 0 ; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                next[i] =  -1;
            else
                next[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = 0; i < n ; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                prev[i] =  -1;
            else
                prev[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i ++)
        {
            int r = next[i];
            if(next[i] == -1)
                r = n;
            int l = prev[i];
            int area = heights[i] * (r - l - 1);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};