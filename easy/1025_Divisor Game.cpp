class Solution {
public:
    bool divisorGame(int N) {
        // Method 1:
        // Mathmatical solution
        // return N % 2 == 0;
        

        // Method 2:
        // DP iterative version (can also write recursive version, and use unordered_map as cache)
        // time complexity: O(nlogn), space complexity: O(1001)
        // 0ms, beats 100%
        
        // Main idea:
        // Find all divisor for number N, and find a definitely lose method, so number N can win
        vector<bool> win(1001);
        win[0] = true;
        for(int i = 1; i <= N; i++) {
            bool res = false;
            for(int j = 1; !res && j * j <= i; j++) {
                if(i % j == 0) { res = !win[i - j]; }
            }
            win[i] = res;
        }
        return win[N];
    }
};