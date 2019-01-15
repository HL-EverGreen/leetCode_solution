class Solution {
public:
    string getHint(string secret, string guess) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.46%
        
        if(secret.empty()) { return "0A0B"; }
        
        int bulls = 0, cows = 0;
        int s1[10] = {0}, s2[10] = {0};
        
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) { bulls++; }
            else {
                s1[secret[i] - '0']++;
                s2[guess[i] - '0']++;
            }
        }
        
        for(int i = 0; i < 10; i++) {
            cows += min(s1[i], s2[i]);                          // calculate cows by each number
        }
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};