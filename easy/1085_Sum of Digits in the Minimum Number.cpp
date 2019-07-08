class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        int target = *min_element(A.begin(), A.end()), sum = 0;
        while(target) {
            sum ^= target % 10;
            target /= 10;
        }
        return (sum & 1) ? 0 : 1;
    }
};