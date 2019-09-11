class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        // binary search & greedy
        // time complexity: O(xlogn), x is the total weights, space complexity: O(1)
        // 44ms, beats 97.57%
        
        // Since we need to find least feasible limit, so we can use binary search.
        // If current limit is valid, search left. Otherwise, search right
        
        int lo = 0, hi = accumulate(weights.begin(), weights.end(), 0);
        for(auto weight : weights) lo = max(lo, weight);
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(checkResult(weights, D, mid)) hi = mid;  // Current limit works
            else lo = mid + 1;                          // Current limit doesn't work
        }
        return lo;
    }
    
    /* Function to check whether it is feasible to transfer package with the given weight limit */
    // *NOTE: The package is loaded in the order given by weights, so it no business of backpack problem
    bool checkResult(vector<int>& weights, int D, int limit) {
        int need = 1, cur = 0;
        for (auto weight : weights) {
            if(cur + weight > limit) {
                cur = 0;
                if(++need > D) return false; 
            }
            cur += weight;
        }
        return true;
    }
};
