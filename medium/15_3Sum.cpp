class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // two pointers
        // time complexity: O(n^2)
        // two pointer and binary search can't work, think thoroughly! (O(nlogn) can't work)
        
        vector<vector<int>> res;
        int n_size = nums.size();
        if(n_size < 3) return res;
        
        // sort input nums
        sort(nums.begin(), nums.end());
        
        // outer loop, loop for first index
        for(int first = 0; first < n_size - 2; first++) {
            int second = first + 1;
            int third = n_size - 1;
            
            // inner loop, loop for second and third index
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                
                if(sum > 0) {           // to large
                    third--;
                } else if(sum < 0) {    // to small
                    second++;
                } else {                // find a solution
                    vector<int> temp;
                    int cur_second = nums[second];
                    int cur_third = nums[third];
                    temp.push_back(nums[first]);
                    temp.push_back(cur_second);
                    temp.push_back(cur_third);
                    res.push_back(temp);
                    
                    // eliminate duplicated second index
                    while(second < third && nums[second] == cur_second) {
                        second++;
                    }
                    
                    // eliminate duplicated third index
                    while(second < third && nums[third] == cur_third) {
                        third--;
                    }    
                }
            }
            
            // eliminate duplicated first index
            while(first < n_size - 1 && nums[first] == nums[first + 1]) {
                first++;
            }
        }
        return res;
    }
};