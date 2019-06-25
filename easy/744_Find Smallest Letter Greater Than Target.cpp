class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 8ms, beats 98.59%
        
        // Method 1:
        // Use upper bound
        /*
        auto iter = upper_bound(letters.begin(), letters.end(), target);
        return iter == letters.end() ? *letters.begin() : *iter;
        */
        
        // Method 2:
        // Binary search
        if(letters.back() <= target) { return letters.front(); }
        int lo = 0, hi = letters.size() - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(letters[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return letters[lo];
    }
};