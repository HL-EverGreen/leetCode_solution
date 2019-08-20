class Solution {
public:
    int titleToNumber(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        int res=0;
        long temp=1;
        if(s.length()==0) return res;
        for(int i = s.length() - 1; i >= 0; i--){
            res += temp * (s[i] - 'A' + 1);
            temp *= 26;
        }
        return res;
    }
};