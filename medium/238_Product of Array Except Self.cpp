class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p=1;
        vector<int> res;
        if(nums.size()>0){
            res.push_back(1);
            for(int i=0;i<nums.size()-1;i++){ //product from left
                res.push_back(res[i]*nums[i]);
            }
            for(int i=nums.size()-1;i>=0;i--){ //product from right
                res[i]*=p;
                p*=nums[i];
            }    
        }
        return res;
    }
};