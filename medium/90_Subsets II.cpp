class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // array
        // time complexity: O(n^2). space complexity: O(2^n)
        // 8ms, beats 57.14% 
        
        // method 1
        // use current all res to update new one
        // if duplicate, then no need to set $start$ to 0, so that it will only add to those updated in last round
        vector<vector<int>> res = {{}};
        int start;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i - 1] != nums[i]) { start = 0; }
            for(int end = res.size(); start < end; start++) {
                vector<int> group = res[start];
                group.push_back(nums[i]);
                res.push_back(group);
            }
        }
        return res;
    }
    
    // method 2: DFS
    // for duplicates: only add it when i == begin, which can ensure only add one same element in this iteration
    /*
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
        std::vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
    }
    
private:
    void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i)
            if (i == begin || nums[i] != nums[i - 1]) { 
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i + 1);
                vec.pop_back();
            }
    }
    */
};