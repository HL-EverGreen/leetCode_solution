class Solution {
public:
    string predictPartyVictory(string senate) {
        // greedy
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 89.33%
        
        // main idea:
        // Push all R and D into two queues.
        // Compare each R with D, and eliminate one. 
        // Push the remain one into queue and continue;
        
        queue<int> q1, q2;
        int N = senate.length();
        for(int i = 0; i < N; ++i) {            // Initialize queue
            if(senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }
        
        while(!q1.empty() && !q2.empty()) {     // Compare each R&D pair
            int v1 = q1.front(); q1.pop();
            int v2 = q2.front(); q2.pop();
            if(v1 < v2) q1.push(v1 + N);        // R remains, update its id and keep it
            else q2.push(v2 + N);               // D remains, update its id and keep it
        }
        
        if(q1.empty()) return "Dire";
        else return "Radiant";
        
        
        // Another greedy solution
        // time complexity: O(n), space complexity: O(n), 8ms
        // Main idea is the same
        
        int count = 0, len = 0;
        // When the length of senate doesn't decrease, the game is over.
        while (senate.size() != len) {
            string s;
            len = senate.size();
            for (int i = 0; i < len; i++) {
                if (senate[i] == 'R') {
                    if (count++ >= 0) s += 'R';
                }
                else if (senate[i] == 'D') {
                    if (count-- <= 0) s += 'D';
                }
            }  
            swap(s, senate);
        }
        if (senate[0] == 'R') 
            return "Radiant";
        else 
            return "Dire";
        
    }
};