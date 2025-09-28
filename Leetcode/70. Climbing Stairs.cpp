vector<int> num_of_ways(46, -1);
class Solution {
public:
    int climbing(int n)
    {
        if(num_of_ways[n] != -1)    return num_of_ways[n];
        return num_of_ways[n] = climbing(n - 1) + climbing (n - 2);
    }
    int climbStairs(int n) {
        num_of_ways[0] = 1;
        num_of_ways[1] = 1;
        return climbing(n);
    }
};