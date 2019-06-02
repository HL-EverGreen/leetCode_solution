class Solution {
public:
    string removeDuplicates(string S) {
        // string & stack
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 96.55%
        
        // Main idea:
        // Use a string as stack, compare stack top element with current element
        string stk;
        
        for(auto ch : S) {
            if(stk.length() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
        
        // Method 2:
        // Recursive
        /*
        for (auto i = 1; i < S.size(); ++i) {
            if (S[i - 1] == S[i]) {
                return removeDuplicates(S.substr(0, i - 1) + S.substr(i + 1));
            }
        }
        return S;
        */
    }
};