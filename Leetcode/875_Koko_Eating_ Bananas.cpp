class Solution {
public:
    bool check(vector<int> &piles, int k, int h){
        long long count = 0;
        for(int i = 0; i < piles.size(); i++)   count += (piles[i] - 1) / k + 1;
        return count <= h ? 1 : 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_rate = 0;
        for(int i = 0; i < piles.size(); i++)   max_rate = max(max_rate, piles[i]);
        int min_rate = 1; 
        int ans = 0;
        while(min_rate <= max_rate){
            int mid = (max_rate - min_rate) / 2 + min_rate;
            if(check(piles, mid, h)){
                ans = mid;
                max_rate = mid - 1;
            }
            else    min_rate = mid + 1;
        }
        return ans;
    }
};