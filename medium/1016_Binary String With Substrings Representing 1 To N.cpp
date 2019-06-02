class Solution {
public:
    bool queryString(string S, int N) {
        // string
        // time complexity: O(S^2), space complexity: O(1)
        // 4ms, beats 97.48%
        
        /* Method 1 */
        // Based on N, time complexity: O(S^2)
        // Main idea:
        // Just need to find the upper half, because if upper half exists, the lower half is there
        for(int i = N; i > N / 2; i--) {
            string cur = bitset<32>(i).to_string();
            if(S.find(cur.substr(cur.find('1'))) == string::npos) { return false; }
        }
        return true;
        
        
        /* Method 2 */
        // Based on S, time complexity: O(SlogN), but space complexity is really big
        /*
        vector<bool> seen(N);
        int X = 0;
        for (auto i = 0; i < S.size() && X < N; ++i) {
            if (S[i] == '0') continue;
            for (auto j = i, num = 0; num <= N && j < S.size(); ++j) {
                num = (num << 1) + S[j] - '0';
                if (num > 0 && num <= N && !seen[num - 1]) {
                    ++X;
                    seen[num - 1] = true;
                }
            }
         }
         return X == N;
        */
    }
};