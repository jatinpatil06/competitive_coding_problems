class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles >= numExchange){
            int newFull = emptyBottles / numExchange;
            drunk += newFull;
            emptyBottles = emptyBottles % numExchange + newFull;
        }
        return drunk;
    }
};