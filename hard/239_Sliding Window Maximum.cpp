class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {//deque
        deque<int> deq;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(!deq.empty() && deq.front()==i-k) deq.pop_front(); //remove element out of current window
            while(!deq.empty() && nums[deq.back()]<nums[i]) deq.pop_back(); //delete element which need not to be considered
            deq.push_back(i);
            if(i>=k-1) res.push_back(nums[deq.front()]);
        }
        return res;
    }
};