class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // string & hash table
        // time complexity: O(m + n), m is J.length(), n is S.length()
        // space complexity: O(n)
        // 8ms, beats 99.33%
        
        // main idea:
        // use hash table to record all jewels
        unordered_map<char, int> count;
        for(auto ch : S) count[ch]++;
        int res = 0;
        for(auto ch : J) {
            if(count.find(ch) != count.end()) res += count[ch];
        }
        return res;
    }
};