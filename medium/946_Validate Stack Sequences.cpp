class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // stack
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 92.94%
        
        // Main idea:
        // Use real stack to continually push elements, and repeatedly
        // compare topest element with next element in `popped`
        stack<int> s;
        int pop_i = 0;
        
        for(auto v : pushed) {
            s.push(v);
            while(!s.empty() && s.top() == popped[pop_i]) {
                s.pop();
                ++pop_i;
            }
        }
        return s.empty();
    }
};