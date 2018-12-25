class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // array
        // time complexity: O(n^3)
        // 20ms, beats 80.46%
        
        vector<vector<int>> res;
        if(nums.empty()) { 
            return res;
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            int target_3 = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                int target_2 = target_3 - nums[j];
                int front = j + 1, back = nums.size() - 1;
                while(front < back) {
                    int sum_two = nums[front] + nums[back];
                    if(sum_two < target_2) {
                        front++;
                    } else if(sum_two > target_2) {
                        back--;
                    } else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                        // check duplicate for third number
                        while(front < back && nums[front] == quadruplet[2]) {
                            front++;
                        }
                        // check duplicate for fourth number
                        while(front < back && nums[back] == quadruplet[3]) {
                            back --;
                        }
                    }
                }
                // check duplicate for second number
                while(j < nums.size() - 1 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            // check duplicate for first number
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return res;
    }
};