class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0, r = 0;
        double sum = 0, avg = 0;
        for(r = 0; r < k; r++)
            sum += nums[r];
        double max_avg = sum / k;
        int n = nums.size();
        while(r < n)
        {
            sum += nums[r] - nums[l];
            max_avg = max(max_avg, sum / k);
            l++;
            r++;
        }
        return max_avg;
    }
};