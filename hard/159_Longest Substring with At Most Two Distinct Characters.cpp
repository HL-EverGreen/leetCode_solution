class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // string & two pointers
        // time complexity: O(n), space complexity: O(1)
        
        // method 1:
        // use table
        // 4ms, beats 100%
        /*
        int dict[256] = {0}, len = 0, start = 0, count = 0;
        //fill_n(dict, 256, 0);
        for(int i = 0; i < s.size(); i++) {
            if(++dict[s[i]] == 1) { count++; }
            while(count > 2) {
                if(--dict[s[start]] == 0) { count--; }
                start++;
            }
            len = max(len, i - start + 1);
        }
        return len;
        */
        
        // method 2:
        // use two variables
        // 4ms, beats 100%
        int len = 0, cur = 0, lastOneCount = 0, num1 = s[0], num2 = s[0];
        for(char ch : s) {
            if(ch == num2) {
                lastOneCount++;
                cur++;
            } else if(ch == num1) {
                lastOneCount = 1;
                cur++;
                num1 = num2;
                num2 = ch;
            } else {
                cur = lastOneCount + 1;
                lastOneCount = 1;
                num1 = num2;
                num2 = ch;
            }
            len = max(len, cur);
        }
        return len;
    }
};