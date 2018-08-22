class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //a much simplier solution of same main idea
        const int size_n = nums.size();
        vector<string> res;
        if ( 0 == size_n) return res;
        for (int i = 0; i < size_n;) {
            int start = i, end = i;
            while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
            if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else res.push_back(to_string(nums[start]));
            i = end+1;
        }
        return res;
        
        //my clumsy solution
        /*
        int n_size=nums.size();
        vector<string> res;
        if(n_size<=0) return res;
        int pre_index=-1;
        for(int i=0;i<n_size;i++){
            if(i==0){
                pre_index=0;
                continue;
            }
            if(nums[i]==nums[i-1]+1) continue;
            else{
                if(i==pre_index+1) res.push_back(to_string(nums[i-1]));
                else res.push_back(to_string(nums[pre_index])+"->"+to_string(nums[i-1]));
                pre_index=i;
            }
        }
        if(pre_index==n_size-1) res.push_back(to_string(nums[n_size-1]));
        else if(pre_index<n_size-1) res.push_back(to_string(nums[pre_index])+"->"+to_string(nums[n_size-1]));
        return res;
        */
    }
};