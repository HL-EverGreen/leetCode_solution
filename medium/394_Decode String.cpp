class Solution {
public:
    string decodeString(string s) {
        // recursive & stack
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // Use stack to store count of string and current string when encounter '['
        // And recalculate current string when encounter ']'
        
        stack<int> count;
        stack<string> stash_str;
        int len = s.length();
        int cur_cnt = 0;
        string cur_str = "";
        
        for(int i = 0; i < len; i++) {
            if(isalpha(s[i])) {                         // String
                cur_str.push_back(s[i]);
            } else if(isdigit(s[i])) {                  // Number
                cur_cnt = cur_cnt * 10 + (s[i] - '0');
            } else if(s[i] == '[') {                    // Encounter '[', push current cnt and string
                count.push(cur_cnt);
                stash_str.push(cur_str);
                cur_cnt = 0;
                cur_str = "";
            } else if(s[i] == ']') {                    // Encounter ']', recalculate current string
                cur_cnt = count.top();
                count.pop();
                cur_str = combineString(cur_str, cur_cnt);
                cur_cnt = 0;
                cur_str = stash_str.top() + cur_str;
                stash_str.pop();
            }
        }
        return cur_str;
    }
    
    /* Helper function to combine n string and return result */
    string combineString(string& target, int cnt) {
        string res;
        for(int i = 0; i < cnt; i++) {
            res.append(target);
        }
        return res;
    }
};