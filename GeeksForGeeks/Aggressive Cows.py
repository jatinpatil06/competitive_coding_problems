class Solution:
    def check(self, stalls, min_dist, cows):
        count = 1
        last_placed = 0
        for idx in range(1, len(stalls)):
            if(stalls[idx] - stalls[last_placed] >= min_dist):
                last_placed = idx
                count += 1
        if(count >= cows):
            return True
        else:
            return False
            
    def aggressiveCows(self, stalls, k):
        stalls.sort()
        low = stalls[1] - stalls[0]
        high = stalls[-1] - stalls[0]
        for idx in range(1, len(stalls)):
            low = min(low, stalls[idx] - stalls[idx - 1])
            high = max(high, stalls[idx] - stalls[idx - 1])
            
        while(low <= high):
            mid = low + (high - low) // 2
            if(self.check(stalls, mid, k)):
                answer = mid
                low = mid + 1
            else:
                high = mid - 1
        return answer