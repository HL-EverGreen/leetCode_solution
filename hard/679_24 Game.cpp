class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        // dfs
        // 16ms, beats 78.65%
        
        // main idea:
        // Convert all number to double first.
        // For each given num, check size: 
        // 1) If size == 1, check if == 24
        // 2) Else, choose two number to calculate first, and push the result and 
        //    other numbers into vector and call find24() again (key point)
        
        vector<double> vec;
        for(auto n : nums) vec.push_back(n * 1.0);
        return find24(vec);
    }
    
    bool find24(vector<double>& nums) {
        if(nums.size() == 1) return abs(nums.front() - 24.0) <= elipson;                    // size == 1
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(i == j) continue;
                vector<double> next;
                for(int k = 0; k < size; k++) if(k != i && k != j) next.push_back(nums[k]); // push other numbers
                for(auto op : operations) {
                    if((op == '+' || op == '*') && i > j) continue;                         // avoid calculate again
                    if(op == '/' && nums[j] == 0) continue;
                    switch(op) {
                        case '+': next.push_back(nums[i] + nums[j]); break;
                        case '-': next.push_back(nums[i] - nums[j]); break;
                        case '*': next.push_back(nums[i] * nums[j]); break;
                        case '/': next.push_back(nums[i] / nums[j]); break;
                    }
                    if(find24(next)) return true;                                           // check this branch
                    next.pop_back();                                                        // recover vector
                }
            }
        }
        return false;
    }
private:
    double elipson = pow(10.0, -5);
    vector<char> operations = {'+', '-', '*', '/'};
};