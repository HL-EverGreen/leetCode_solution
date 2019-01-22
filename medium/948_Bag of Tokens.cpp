class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        // array & greedy
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // two pointers:
        // use power to exchange count for small token[i]
        // use count to exchange large power for big token[j]
        sort(tokens.begin(), tokens.end());
        int cnt = 0, res = 0, i = 0, j = tokens.size() - 1;
        
        while(i <= j){
            if(P >= tokens[i]) {
                P -= tokens[i++];
                res = max(res, ++cnt);
            } else if(cnt) {
                P += tokens[j--];
                cnt--;
            } else break;
        }
        return res;
    }
};