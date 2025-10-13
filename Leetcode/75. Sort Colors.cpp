class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        /*
        Better approach
        map<int, int> colour_freq;
        for(int i = 0; i < nums.size(); i++)    colour_freq[nums[i]]++;
        int i = 0;
        for(i = 0; i < colour_freq[0]; i++) nums[i] = 0;
        for(; i < colour_freq[0] + colour_freq[1]; i++) nums[i] = 1;
        for(; i < colour_freq[0] + colour_freq[1] + colour_freq[2]; i++) nums[i] = 2;
        */
        //An optimal approach would be to use the Dutch National Flag Algorithm
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)  mid++;
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};