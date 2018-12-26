class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // array
        // time complexity: O(n)
        // if all number is 9, set first digit to 1 and others to 0, then push one more 0 to the vector
        
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};