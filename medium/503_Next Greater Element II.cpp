class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // array & stack
        // time complexity: O(n), space complexity: O(n)
        // 84ms, beats 92.79%
        
        // Main idea:
        // Loop twice. Same idea as the problem version I.
        
        // Loop from start to end
        // int n = nums.size();
        // vector<int> stack, res(n, -1);
        // for (int i = 0; i < n * 2; ++i) {
        //     int idx = i % n;
        //     while (stack.size() && nums[stack.back()] < nums[idx]) {
        //         res[stack.back()] = nums[idx];
        //         stack.pop_back();
        //     }
        //     stack.push_back(idx);
        // }
        // return res;
        
        // Loop from end to start
        // Much efficient than loop from start, since loop from end can utilize current index info
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);
        
        for(int i = 2 * n - 1; i >= 0; --i) {
            int num = nums[i % n];
            while(!s.empty() && s.top() <= num) s.pop();
            if(!s.empty()) res[i % n] = s.top();
            s.push(num);
        }
        return res;
    }
};