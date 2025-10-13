class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int last_unique = arr[0], j = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != last_unique){
                last_unique = arr[i];
                arr[j++] = last_unique;
            }
        }
        return j;
    }
};