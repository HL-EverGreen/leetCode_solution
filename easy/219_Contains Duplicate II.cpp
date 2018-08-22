class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {//unordered_set
        //the main idea is to store the last k elments in set and compare the new val to each element in the set
        //and update set when set.size()>k
        if(k<=0) return false;
        int n_size=nums.size();
        if(k>=n_size) k=n_size-1;
        unordered_set<int> mySet;
        
        for(int i=0;i<n_size;i++){
            if(i>k) mySet.erase(nums[i-k-1]);
            if(mySet.find(nums[i])!=mySet.end()) return true;
            mySet.insert(nums[i]);
        }
        return false;
    }
};