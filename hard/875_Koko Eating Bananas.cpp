class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // binary search
        // time complexity: O(log(1e9)n), n is the piles.size()
        // space complexity: O(1)
        // 64ms, beats 83.33%
        
        // Main idea:
        // Each binary search, use mid to present current attempt number.
        // If current number is enough, continue search in lower range.
        int lo = 1, hi = 1e9;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2, total = 0;
            for(auto pile : piles) {
                total += (pile + mid - 1) / mid;        // 上取整
            }
            
            if(total > H) { 
                lo = mid + 1; 
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};