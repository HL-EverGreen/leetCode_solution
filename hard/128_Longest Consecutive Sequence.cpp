class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //use unordered_map, O(n)
        /*
        unordered_map<int,int> mp;
        int res=0;
        for(auto num:nums){
            if(mp[num]) continue;
            res=max(res,mp[num]=mp[num-mp[num-1]]=mp[num+mp[num+1]]=mp[num-1]+mp[num+1]+1);
        }
        return res;
        */
        
        //use unordered_set, O(n)
        unordered_set<int> tmp(nums.begin(),nums.end());
        int prev,next,res=0;
        for(auto num:nums){
            if(tmp.find(num)==tmp.end()) continue;
            //tmp.erase(num); //skip this step can save plenty of running time(as erase this num is unnecessary)
            prev=num-1;
            next=num+1;
            while(tmp.find(prev)!=tmp.end()) tmp.erase(prev--);
            while(tmp.find(next)!=tmp.end()) tmp.erase(next++);
            res=max(res,(next-prev-1));
        }
        return res;
        
    }
};