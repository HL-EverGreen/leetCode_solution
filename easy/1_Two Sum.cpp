class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // array & hash table
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 99.95%
        
        int size = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < size; i++) {
            if(m.find(target - nums[i]) != m.end()) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};

        // Brute force, O(n^2);
        /*
        vector<int> res(2);
        for(int i = 0; i < nums.size()-1;i++)
        {
            for(int j=i+1; j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    res[0]=i;
                    res[1]=j;
                    return res;
                }
            }
        }
        */
    }
};