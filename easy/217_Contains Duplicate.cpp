class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       /*
        map<int,int> myMap;
        for(int num:nums){
            if(myMap.find(num)!=myMap.end())
                return true;
            else myMap[num]=1;
        }
        return false;
        */
        
        //use set
        //return nums.size()!=unordered_set<int>(nums.begin(),nums.end()).size();
        
        //use set instead of map when we don't care the frequency of the numbers
        unordered_set<int> link;
        for(int num:nums){
            if(link.find(num)!=link.end())
                return true;
            link.insert(num);
        }
        return false;
    }
};