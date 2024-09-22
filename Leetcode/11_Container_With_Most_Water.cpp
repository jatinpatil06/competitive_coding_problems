class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        int i = 0; 
        int j = height.size() - 1;
        int volume = -1;
        while(i < j)
        {
            volume = max(volume, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return volume;
    }
};