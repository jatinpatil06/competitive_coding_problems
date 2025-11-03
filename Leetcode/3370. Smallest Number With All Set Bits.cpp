class Solution {
public:
    int smallestNumber(int n) {
        while(true){
            int copy = n;
            while(copy > 0){
                if(!(copy & 1)){
                    n++;
                    break;
                }  
                copy = copy >> 1;    
            }
            if(copy == 0)   return n;
        }
    }
};