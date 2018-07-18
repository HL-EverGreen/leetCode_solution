class Solution {
public: //closure number
    map<int,vector<string>> mp;
    vector<string> generateParenthesis(int n) {
        if (mp.find(n) != mp.end()) return mp[n];
        vector<string> ans;
        if (0 == n) {
            ans.push_back("");
        } else {
            for (int c = 0; c < n; ++c) {
                vector<string> left = generateParenthesis(c);
                for (int i = 0; i < left.size(); i++) {
                    vector<string> right = generateParenthesis(n - 1 - c);
                    for (int j = 0; j < right.size(); j++) {
                        ans.push_back("(" + left[i] + ")" + right[j]);
                    }
                }
            }
        }
        mp[n] = ans;
        return ans;        
    }
};
