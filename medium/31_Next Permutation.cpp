class Solution {
public:
    void nextPermutation(vector<int>& nums) {//next_permutation
        int i=nums.size()-1, k=i;
        //从后往前找到第一个小于后面元素的元素
        //将该元素后所有元素反向
        //从反向后该元素的位置向后找，找到第一个比该元素大的值并将其与该元素交换（若i==0则省略该步骤，即反向后已经是最小排列）
        while(i>0 && nums[i-1]>=nums[i]) i--;
        for(int j=i;j<k;j++,k--) swap(nums[j],nums[k]);
        if(i>0){
            k=i--; //k=i,i--;
            while(nums[k]<=nums[i]) k++;
            swap(nums[i],nums[k]);
        }
    }
};