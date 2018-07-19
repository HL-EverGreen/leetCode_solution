class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.size()<=1)
            return res;
        int index1=0;
        int index2=1;
        while(numbers[index1]+numbers[index2]!=target){
            while(numbers[index1]+numbers[index2]<target){
                index2++;
            }
            if(numbers[index1]+numbers[index2]==target){
                res.push_back(index1+1);
                res.push_back(index2+1);
                return res;
            }
            index1++;
            while(numbers[index1]+numbers[index2]>target){
                index2--;
            }
            if(numbers[index1]+numbers[index2]==target){
                res.push_back(index1+1);
                res.push_back(index2+1);
                return res;
            }
        }
        res.push_back(index1+1);
        res.push_back(index2+1);
        return res;
    }
};