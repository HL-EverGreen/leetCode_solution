class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        // DFS + memo
        // time complexity: O(n^2), space complexity: O(n^2)
        // 0ms, beats 100%
        
        // Main idea:
        // For each string, try on each operator(+, -, *) by first calculating both sides and finally calculate this operator.
        // Use memo to cache the calculated result for specific string.
        
        if(memo.count(input)) return memo[input];
        
        vector<int> res;
        for(int i = 0; i < input.length(); ++i) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));   // Left side
                vector<int> right = diffWaysToCompute(input.substr(i + 1)); // Right side
                for(int& l : left) {
                    for(int& r : right) {
                        switch(input[i]) {
                            case '+': res.push_back(l + r); break;
                            case '-': res.push_back(l - r); break;
                            case '*': res.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if(res.empty()) res.push_back(stoi(input)); // Only contains digit
        return memo[input] = res;
    }
private:
    unordered_map<string, vector<int>> memo;
};