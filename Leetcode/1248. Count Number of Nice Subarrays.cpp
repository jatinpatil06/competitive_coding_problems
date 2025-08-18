class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int l = 0, r = 0, no_of_subars = 0, c = 0;
        while(r < nums.size())
        {
            if(nums[r] % 2 == 1)    c++;
            while(c > k)
            {
                if(nums[l] % 2 == 1)    c--;
                l++;
            }
            no_of_subars += r - l + 1;
            r++;
        }
        return no_of_subars;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};