class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {//two side
        //first<second<third,sum=nums[fi]+nums[se]+nums[th]
        //when sum==target return
        //when sum>target se++
        //when sum<target th--
        int n_size=nums.size();
        if(n_size<3) return 0;
        int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int fi=0;fi<n_size-2;fi++){
            if(fi>0 && nums[fi]==nums[fi-1]) continue;
            int se=fi+1, th=n_size-1;
            while(se<th){
                int sum=nums[fi]+nums[se]+nums[th];
                closest=abs(target-sum)<abs(target-closest)?sum:closest;
                if(closest==target) return closest;
                if(sum>target) th--;
                else se++;
            }
        }
        return closest;
    }
};