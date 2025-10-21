class Solution {
public:
    int climb(vector<int> &ways, int n){
        if(ways[n] != -1)   return ways[n];
        else{
            ways[n] = climb(ways, n - 1) + climb(ways, n - 2);
            return ways[n];
        }
    }
    int climbStairs(int n) {
        vector<int> ways(46, -1);
        ways[1] = 1;
        ways[2] = 2;
        climb(ways, n);
        return ways[n];
    }
};