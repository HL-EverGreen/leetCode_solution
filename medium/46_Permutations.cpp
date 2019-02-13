class Solution {
public:
    // array_perm
    // 16ms, beats 100%
    
    // main idea:
    // perm({1,2,3,4})=1perm({2,3,4})+2perm({1,3,4})+3perm({1,2,4})+4perm({1,2,3})
    // so just swap each element to the front and do recursion
    
    vector<vector<int>> res;
    
    void perm(vector<int>& nums, int start, int end) {
        if(start == end) {
            res.push_back(nums);
            return;
        }
        for(int i = start; i <= end; i++) {
            swap(nums[start], nums[i]);
            perm(nums, start + 1, end);                     // notice, here is start + 1 instead of i + 1 !!
            swap(nums[start], nums[i]);
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        perm(nums, start, end);
        return res;
    }
};

// trivial.. use next_permutation()
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            res.push_back(nums);
        }
        return res;
    }
};
*/