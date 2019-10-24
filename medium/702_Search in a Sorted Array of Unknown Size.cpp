// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 48ms, beats 93.62%
        
        // Main idea:
        // First determine target's range (using exponential try)
        // Then do binary search in this range
        
        int lo, hi = 1;
        
        // Find range that include target
        while(reader.get(hi) < target) hi <<= 1;
        lo = hi >> 1;
        
        // Do binary search in that range
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = reader.get(mid);
            if(cur == target) return mid;
            else if(cur > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};