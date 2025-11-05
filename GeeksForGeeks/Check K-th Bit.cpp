class Solution {
  public:
    bool checkKthBit(int n, int k) {
        if((1 << k) & n)    return true;
        return false;
    }
};