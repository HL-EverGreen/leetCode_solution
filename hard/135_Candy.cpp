class Solution {
public:
    int candy(vector<int>& ratings) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 24ms, beats 98.93%
        
        // two turns, one from left to right and one from right to left
        int num = ratings.size(), res = 0;
        vector<int> candy(num, 1);
        if(num < 2) { return num; }
        
        for(int i = 1; i < num; i++) {
            if(ratings[i] > ratings[i - 1]) { candy[i] = candy[i - 1] + 1; }
        }
        
        for(int i = num - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) { candy[i] = max(candy[i], candy[i + 1] + 1); }
        }
        
        for(auto n : candy) {
            res += n;
        }
        return res;
    }
};