class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> myMap;
        for(int i=0;i<nums.size();i++){
            if(myMap.find(nums[i])!=myMap.end()) myMap[nums[i]]+=1;
            else myMap[nums[i]]=1;
        }
        map<int,int>::iterator iter;
        for(iter=myMap.begin();iter!=myMap.end();iter++){
            if(iter->second>(nums.size()/2)) return iter->first;
        }
    }
};