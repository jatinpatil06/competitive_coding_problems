class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long diff = 0;
        int n = nums.size();
        /* Brute Force Approach with TC = O(N ^ 2)
        for(int i = 0; i < n; i++){
            int max_elem = nums[i], min_elem = nums[i];
            for(int j = i; j < n; j++){
                max_elem = max(max_elem, nums[j]);
                min_elem = min(min_elem, nums[j]);
                diff += abs(max_elem - min_elem);
            }
        }

        An optimal approach would be to use monotonic stacks
        */

        vector<int> nge(n), pge(n), nse(n), pse(n);
        stack<int> st1, st2;
        for(int i = n - 1; i >= 0; i--){
            //finding the next greater element
            while(!st1.empty() && nums[st1.top()] <= nums[i]) st1.pop();
            if(st1.empty())  nge[i] = n;
            else    nge[i] = st1.top();
            st1.push(i);
            //finding the next smaller element
            while(!st2.empty() && nums[st2.top()] >= nums[i]) st2.pop();
            if(st2.empty())  nse[i] = n;
            else    nse[i] = st2.top();
            st2.push(i);
        }
        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();
        for(int i = 0; i < n; i++){
            //finding the previous greater element
            while(!st1.empty() && nums[st1.top()] < nums[i]) st1.pop();
            if(st1.empty())  pge[i] = -1;
            else    pge[i] = st1.top();
            st1.push(i);
            //finding the previous smaller element
            while(!st2.empty() && nums[st2.top()] > nums[i]) st2.pop();
            if(st2.empty())  pse[i] = -1;
            else    pse[i] = st2.top();
            st2.push(i);
        }

        //in what subarrays is each element the smallest and largest
        for(int i = 0; i < n; i++){
            //largest
            int l = i - pge[i], r = nge[i] - i;
            diff += 1LL * nums[i] * (r * l);
            //smallest
            l = i - pse[i];
            r = nse[i] - i;
            diff -= 1LL * nums[i] * (r * l);
        }
        return diff;
    }
};