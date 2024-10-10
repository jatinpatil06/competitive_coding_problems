class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n == 1 || n==2)
            return 1;
        int* tribo_arr = new int[n+1];
        tribo_arr[0] = 0;
        tribo_arr[1] = 1;
        tribo_arr[2] = 1;
        for(int i = 3; i <= n; i++)
            tribo_arr[i] = tribo_arr[i-1] + tribo_arr[i-2] + tribo_arr[i-3];
        return tribo_arr[n];
    }
};