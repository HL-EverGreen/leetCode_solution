class Solution {
public:
    string reorganizeString(string S) {
        // string & greedy
        // time complexity: O(nlogn), space complexity: O(n)
        // 0ms, beats 100%
        
        // Sort the string by occurrence, i.e. the character with most occurrence is at front.
        // Next, let i = 0 at the beginning, j = (n-1)/2+1 in the middle.
        // We can build the answer by appending s[i++] and s[j++] sequentially.
        int count[26] = {0}, size = S.length();
        string newStr, res;
        for(auto ch : S) count[ch - 'a']++;                                     // get frequency
        
        vector<pair<int, char>> charCount;
        for(int i = 0; i < 26; i++) {
            if(count[i] > (size + 1) / 2) return "";
            charCount.push_back(make_pair(count[i], 'a' + i));
        }
        sort(charCount.rbegin(), charCount.rend());
        for(auto c : charCount) newStr += string(c.first, c.second);            // construct sorted string
        
        for(int i = 0, j = (size - 1) / 2 + 1; i <= (size - 1) / 2; i++, j++) { // reorganize the string
            res += newStr[i];
            if(j < size) res += newStr[j];
        }
        return res;
    }
};