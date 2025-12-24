class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*  Brute Force with TC = O(logN)
        //negative numbers cannot be a power of 2
        //Additinally, -ve numbers will always have MSB set to 1, resulting in infinite loop
        if(n <= 0)  return false;
        int bits_set = 0;
        while(n){
            if(n & 1)   bits_set++;
            n = n >> 1;
        }
        return bits_set == 1;

            An optimal approach would be to use this trick - n & (n - 1) == 0
            This is valid only for when n is a power of 2
        */
        return (n > 0 && !(n & (n - 1)));
    }
};