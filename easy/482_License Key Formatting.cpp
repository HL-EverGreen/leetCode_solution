class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 12ms, beats 93.42%
        
        // add char from back to front, and check size of res (if size%(K+1)==K, then add '-')
        string res;
        for(auto i = S.rbegin(); i < S.rend(); i++) {
            if(*i != '-') {
                if(res.size() % (K + 1) == K) { res += '-'; }
                res += toupper(*i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};