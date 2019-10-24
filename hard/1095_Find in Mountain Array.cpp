/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 4ms, beats 98.23%
        
        // Main idea:
        // Since directly use binary search is not so elegant (but still work I think,
        // only need to record first search index and direction, so in second search can
        // change the direction.),
        // We can use binary search to find the peak element first.
        // And binary search in (low, peak) and (peak, high) if necessary.
        // So triple binary search are implemented.
        // ***Implement cache can reduce the number of calling mountainArr.get()
        
        int N = mountainArr.length();
        int peak = -1;
        int left = 0, right = N - 1;
        
        // Find peak index
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) >= mountainArr.get(mid + 1)) right = mid;
            else left = mid + 1;
        }
        peak = left;
        
        // Search left part
        left = 0; right = peak;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cur = mountainArr.get(mid);
            if(cur == target) return mid;
            else if(cur > target) right = mid - 1;
            else left = mid + 1;
        }
        
        // Search right part
        left = peak; right = N - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cur = mountainArr.get(mid);
            if(cur == target) return mid;
            else if(cur > target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};