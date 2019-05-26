class Solution {
public:
    vector<int> diStringMatch(string S) {
        // pattern & two pointers
        // time complexity: O(n), space complexity: O(1)
        // 36ms, beats 99.39%
        
        // Main idea:
        // Keep tracking of smallest and largest number.
        // When encounter 'I', put the smallest number. (which is the safest, since all rest numbers are greater than it)
        // When encounter 'D', put the largest number. (the same)
        int size = S.length();
        vector<int> res;
        
        for(int i = 0, low = 0, high = size; i <= size; i++) {
            res.push_back(S[i] == 'I' || i == size ? low++ : high--);
        }
        return res;
    }
};