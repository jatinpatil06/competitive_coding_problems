class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int tail = 0, head = -1;
            int count = 0, ans = 0;
    
            while(tail < n) //the next element exists
            {
                while((head < n - 1) && (count < k || nums[head + 1] == 1)) //the next element exists and count < k or next element is 1
                {
                    head++;
                    if(nums[head] == 0)
                        count++;
                }
                ans = max(ans, head - tail + 1);    //updating the answer
    
                if(tail > head) //if the window is invalid, making the window size zero
                {
                    tail++;
                    head = tail - 1;
                }
                else    //moving the tail ahead
                {
                    if(nums[tail] == 0)
                        count--;
                    tail++;
                }
            }
            return ans;
        }
    };