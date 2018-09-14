class Solution {
public:
    int maxProduct(vector<int>& nums) { //subarray
        int frontProduct=1, backProduct=1, n_size=nums.size(), res=INT_MIN;
        for(int i=0;i<n_size;i++){ //calculate product from two directions
            frontProduct*=nums[i];
            backProduct*=nums[n_size-1-i];
            res=max(res,max(frontProduct, backProduct));
            frontProduct=frontProduct==0?1:frontProduct; //eliminate 0's influence
            backProduct=backProduct==0?1:backProduct;
        }
        return res;
    }
};