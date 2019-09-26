class Solution {
public:
    int maximumSwap(int num) {
        // string
        
        // Method 1:
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Find from back to start and continually update max value and its position.
        // For each value smaller than max, it's switchable, so record this switch's position.
        // After iteration, swap two positions.
        
        string number = to_string(num);
        int left = 0, right = 0;
        int max = -1, max_index = 0;
        int len = number.length();
        
        for(int i = len - 1; i >= 0; --i) {
            if(number[i] > max) {           // Find largest element
                max = number[i];
                max_index = i;
            } else if(number[i] < max) {    // Find switchable pair, record the position
                left = i;
                right = max_index;
            }
        }
        swap(number[left], number[right]);
        return stoi(number);
        
        
        
        // Method 2: My origin naive solution
        // time complexity: O(n^2), space complexity: O(1)
        // 4ms, beats 54.53%
        
        // Main idea:
        // Determine which char to switch: the switchable condition is existing another value larger than this value.
        
        string number = to_string(num);
        int len = number.length();
        
        for(int start = 0; start < len - 1; ++start) {  // Test all element
            char first = number[start], max = first;
            int index = start;
            for(int i = start + 1; i < len; ++i) {  // Find last largest element
                if(number[i] >= max) {
                    max = number[i];
                    index = i;
                }
            }
            if(max > number[start]) {               // If switchable
                swap(number[start], number[index]);
                break;
            }
        }
        
        return stoi(number);
    }
};