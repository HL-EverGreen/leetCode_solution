/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            res.push_back(nums);
        }
        return res;
    }
};
*/
//don't use next_permutation
 class Solution {
public:
    vector<vector<int>> res;
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    
    //for example: perm({1,2,3,4})=1perm({2,3,4})+2perm({1,3,4})+3perm({1,2,4})+4perm({1,2,3}) 
    void perm(vector<int>& nums,int low,int high){ 
        if(low==high)
            res.push_back(nums);
        for(int index=low;index<=high;index++){
            swap(nums[low],nums[index]);
            perm(nums,low+1,high);
            swap(nums[low],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        perm(nums,low,high);
        return res;
    }
};