class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, max_sum = nums[0];
        /*
        Brute Force Solution TC = O(N ^ 3)
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                sum = 0;
                for(int k = i; k <= j; k++) sum += nums[k];
                max_sum = max(max_sum, sum);
            }
        }

        A better version with TC = O(N ^ 2)
    
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                max_sum = max(sum, max_sum);
            }
        }


        The optimal method would be to use Kadane's Algorithm TC = O(N)
        -- We will decide at each index whether to include the current element or not.
        -- If the current element is making the sum < 0, set sum = 0, starting a fresh subarray
        */
        sum = nums[0], max_sum = sum;
        for(int i = 1; i < n; i++){
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};