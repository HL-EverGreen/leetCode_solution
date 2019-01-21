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
        // First pass record the last position for each letter. 
        // Second pass we keep the maximum position of the letters we have seen so far. If the pointer exceeds the maximum position, we found the part.
        /*
        vector<int> res, pos(26, 0);  
        for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
        for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
            idx = max(idx, pos[S[i] - 'a']);
            if (idx == i) res.push_back(i - exchange(last_i, i + 1) + 1);
        }
        return res;
        */
    }
};