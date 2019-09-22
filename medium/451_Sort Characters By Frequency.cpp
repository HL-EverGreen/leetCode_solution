class Solution {
public:
    string frequencySort(string s) {
        // bucket sort
        // time complexity: O(n), space complexity: O(n), n is the length of input string
        // 16ms, beats 75.32%
        
        // Main idea:
        // Since freq is in range[0, len(s)], so we can use bucket sort to avoid using sort()
        
        unordered_map<char, int> m;
        vector<string> bucket(s.length() + 1);
        
        for(const auto& ch : s) m[ch]++;       // Calculate freq
        for(const auto& it : m) {
            int freq = it.second;
            bucket[freq].append(freq, it.first); // Group into buckets
        }
        
        string res;
        for(auto iter = bucket.rbegin(); iter != bucket.rend(); ++iter) res.append(*iter);
        return res;
    }
};