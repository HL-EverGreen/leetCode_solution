class Solution {
public:
    int calPoints(vector<string>& ops) {
        // stack
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 97.31%
        
        vector<int> stk;
        for(auto cur : ops) {
            if(cur == "C" && !stk.empty()) {
                stk.pop_back();
            } else if(cur == "D" && !stk.empty()) {
                stk.push_back(2 * stk.back());
            } else if(cur == "+" && stk.size() >= 2) {
                stk.push_back(stk.back() + stk[stk.size() - 2]);
            } else if(cur != "C" && cur != "D" && cur != "+") {
                stk.push_back(stoi(cur));
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};