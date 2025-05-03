class Solution {
    public:
        int check(vector<int>piles, int n, int mid, int hours)
        {
            long long int count = 0;
            for(int i = 0; i < n; i++)
                count += (int)ceil((double)piles[i] / mid);
            return count <= hours;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            int high = INT_MIN, low = 1;
            for(int i = 0; i < piles.size(); i++)
                high = max(high, piles[i]);
            
            int ans;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;
                if(check(piles, piles.size(), mid, h) == 1)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            return ans;
        }
    };