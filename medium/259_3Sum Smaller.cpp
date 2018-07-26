class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {//dfs, actually for this kind of question, we could sort NUMS first and then do 
                                                        //iteration from other side(if >, from small side, if <, from big side), and add
                                                        //blockly. EXAMPLE is shown below:
        int res=0;
        dfs(nums,res,target,0,0,0);
        return res;
    }
    
    void dfs(vector<int>& nums, int& res, int target, int start, int count, int sum){
        if(count==3 && sum<target){
            res++;
            return;
        }
        else if(count==3) return;
        
        for(int i=start;i<nums.size();i++){
            dfs(nums,res,target,i+1,count+1,sum+nums[i]);
        }
    }
    
    /*
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i]+nums[i+1]+nums[i+2]>=target)break;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                while(j<k && nums[i]+nums[j]+nums[k]>=target)k--;
                count+=k-j;
                j++;
            }
        }
        return count;
    }
    */
    
};