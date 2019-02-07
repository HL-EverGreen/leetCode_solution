class Solution {
public:
    vector<int> partitionLabels(string S) {
        // string & greedy
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 99.4%
        
        unordered_map<char, int> dict;
        vector<int> res;
        for(auto ch : S) dict[ch]++;
        unordered_set<char> remain;
        int prev = -1;
        for(int i = 0; i < S.length(); i++) {
            if(--dict[S[i]] == 0) { 
                if(remain.find(S[i]) != remain.end()) remain.erase(S[i]);
                if(remain.empty()) {
                    res.push_back(i - prev);
                    prev = i;  
                }
            } else { remain.insert(S[i]); }
        }
        return res;
        
        
        // Much more simple solution
        // string & greedy
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.4%
        
        // Main idea: First pass record the last position for each letter. 
        // Second pass we keep the maximum position of the letters we have seen so far. If the pointer exceeds the maximum position, we found the part.
        /*
        int sSize = S.length(), pos[26] = {0};
        for(int i = 0; i < sSize; i++) {
            pos[S[i] - 'a'] = i;
        }
        
        vector<int> res;
        int max_range = 0, last = -1;
        for(int i = 0; i < sSize; i++) {
            max_range = max(max_range, pos[S[i] - 'a']);
            if(max_range == i) {
                res.push_back(i - last);
                last = i;
            }
        }
        return res;
        */
    }
};