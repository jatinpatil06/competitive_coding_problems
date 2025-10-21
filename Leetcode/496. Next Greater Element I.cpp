class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //monotonic stack to keep track of the next greater element
        stack<int> st;
        //map to store the next greatest element
        unordered_map<int, int> nge;
        //we will now find the nge for each element in nums2 and store in hash map for fast retrieval
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i])  st.pop();
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        //compiling the nge for each element in nums1
        vector<int> answer(nums1.size());
        for(int i = 0; i < nums1.size(); i++)   answer[i] = nge[nums1[i]];
        return answer;
    }
};