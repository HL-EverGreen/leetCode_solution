class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 97.76%
        
        int num5 = 0, num10 = 0;
        for(auto b : bills) {
            if(b == 5) num5++;
            else if(b == 10) { num5--; num10++; } 
            else if(num10 > 0) { num5--; num10--; } 
            else num5 -= 3;
            if(num5 < 0) return false;
        }
        return true;
    }
};