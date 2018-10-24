class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { //hash_map
        //use hash_map, O(n)
        int size = nums.size();
        vector<int> res;
        if(size <= 1) return res;
        unordered_map<int, int> myMap;
        for(int i = 0; i < size; i++){
            if(myMap.find(target - nums[i]) != myMap.end()){
                res.push_back(myMap[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            myMap[nums[i]] = i;
        }

        //O(n^2);
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