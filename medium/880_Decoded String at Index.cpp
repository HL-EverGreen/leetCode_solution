class Solution {
public:
    string decodeAtIndex(string S, int K) {
        // math & string
        // space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Compute N that exceed K first and corresponding index
        // And loop back from index, gradually update N and K until N == K
        
        long N = 0, i = 0;
        for(; N < K; ++i) { // Calculate first N exceed K and corresponding index i
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        }
        
        while(i--) {
            if(isdigit(S[i])) { // If digit, divide N by it and adjust K
                N /= S[i] - '0';
                K %= N;
            }else if(K % N-- == 0) return string(1, S[i]);  // Return when N == K
        }
        return "Can't reach here!";
        
        
        // Naive solution, need O(k) space
        // memory limit exceeded
        // string cur;
        // for(char& ch : S) {
        //     if(isalpha(ch)) cur.push_back(ch);
        //     else if(isdigit(ch)) cur = combineK(cur, ch - '0');
        //     if(cur.length() >= K) break;
        // }
        // return string(1, cur[K - 1]);
    }
    
    // string combineK(string t, int N) {
    //     string res;
    //     for(int i = 0; i < N; ++i) res.append(t);
    //     return res;
    // }
};