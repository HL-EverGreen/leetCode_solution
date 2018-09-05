class Solution {
public:
    int maximumGap(vector<int>& nums) {//bucket
        //devide the (maxVal-minVal) into several bucket depending on the size of the #nums#
        //calculate maximum and minimum element in each bucket(if exist)
        //calculate bucket_min[i+1]-bucket_max[i], return maximum value of it
        int maxVal=INT_MIN, minVal=INT_MAX, nSize=nums.size(), bucketNum, bucketGap, maxGap=INT_MIN, lastMax;
        if(nSize<2) return 0;
        for(auto elem:nums){
            maxVal=max(maxVal,elem);
            minVal=min(minVal,elem);
        }
        bucketGap=max(1,(maxVal-minVal)/(nSize-1)); //avoid bucketGap==0
        bucketNum=(maxVal-minVal)/bucketGap+1;
        
        vector<int> bucketCount(bucketNum,0), bucketMax(bucketNum,INT_MIN), bucketMin(bucketNum, INT_MAX);
        for(auto elem:nums){
            int step=(elem-minVal)/bucketGap;
            bucketCount[step]++;
            bucketMax[step]=max(bucketMax[step],elem);
            bucketMin[step]=min(bucketMin[step],elem);
        }
        
        lastMax=minVal;
        for(int i=0;i<bucketNum;i++){
            if(bucketCount[i]>0){
                maxGap=max(maxGap,bucketMin[i]-lastMax);
                lastMax=bucketMax[i];
            }
        }
        return maxGap;
    }
};