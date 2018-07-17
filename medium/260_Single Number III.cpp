class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //another solution use two XOR is better
        map<int,int> myMap;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(myMap.find(nums[i])!=myMap.end())
                myMap[nums[i]]+=1;
            else myMap[nums[i]]=1;
        }
        map<int,int>::iterator iter;
        for(iter=myMap.begin();iter!=myMap.end();iter++)
            if(iter->second==1)
                res.push_back(iter->first);
        return res;
    }
};