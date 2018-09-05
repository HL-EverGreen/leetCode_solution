class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) { //vector
        //at most two elements would exist in the result, so we only use num1,num2,count1,count2
        int n_size=nums.size(), count1=0, count2=0;
        vector<int> res;
        if(n_size==0) return res;
        if(n_size==1) return vector<int>{nums[0]};
        int num1=nums[0], num2=nums[1];
        for(int i=0;i<n_size;i++){ //determine two numbers which appear more (or equal) time than others
            if(num1==nums[i]) count1++;
            else if(num2==nums[i]) count2++;
            else if(count1==0){ num1=nums[i]; count1=1;}
            else if(count2==0){ num2=nums[i]; count2=1;}
            else { count1--; count2--;}
        }
        
        count1=count2=0;
        for(int i=0;i<n_size;i++){
            if(nums[i]==num1) count1++;
            else if(nums[i]==num2) count2++;
        }
        
        if(count1>n_size/3) res.push_back(num1); //if satisfy the requirement
        if(count2>n_size/3) res.push_back(num2);
        return res;
    }
};