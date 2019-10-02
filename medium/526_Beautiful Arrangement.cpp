class Solution {
public:
    int countArrangement(int N) {
        // dfs + memo
        // 12ms, beats 87.90%
        
        // Main idea:
        // Straight forward dfs. 
        // Use integer 'used' to present whether i is used 'used | (1 << i)'. Add memo with 'used' as key
        
        int used = 0;
        unordered_map<int, int> memo;
        return dfs(memo, used, N, 1);
    }
    
    /* Do dfs and find all possible beautiful arrangements */
    int dfs(unordered_map<int, int>& memo, int& used, int N, int i) {
        if(i > N) return 1;
        if(memo.count(used)) return memo[used];
        
        int res = 0;
        for(int j = 1; j <= N; ++j) {   // Try all candidates
            if((j % i && i % j) || (used & (1 << j))) continue;   // Can's satisfy requirement or used
            used |= (1 << j);
            res += dfs(memo, used, N, i + 1);   // Note: not j + 1!!! Since the step should repeat for N times for N positions
            used &= ~(1 << j);
        }
        
        return memo[used] = res;
    }
};