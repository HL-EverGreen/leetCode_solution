class Solution {
public:
    int jump(vector<int>& nums) {  //bfs
        int n_size=nums.size(), step=0, start=0, end=0;
        while(end<n_size-1){
            step++;
            int maxend=end+1;
            for(int i=start;i<=end;i++){
                if(i+nums[i]>=n_size-1) return step;
                maxend=max(maxend, i+nums[i]);
            }
            start=end+1;
            end=maxend;
        }
        return step;
    }
};