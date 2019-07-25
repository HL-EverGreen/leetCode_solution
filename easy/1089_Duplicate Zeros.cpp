class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // two pointer
        // time complexity: O(n), space complexity: O(1)
        // 
        
        // Main idea:
        // Two pass. First pass count number of 0 so can calculate new array's length if we duplicate all 0
        // Second pass, copy value from old array to new array (in fact, new array is the old array), 
        // so we need to determine whether `idx` has below `size`. Only at that time can we make copy.
        
        int size = arr.size(), idx = size + count(arr.begin(), arr.end(), 0);
        for(int i = size - 1; i >= 0; i--) {
            if(--idx < size) {
                arr[idx] = arr[i];
            }
            
            if(arr[i] == 0 && --idx < size) {
                arr[idx] = 0;
            }
        }
    }
};