class Solution {
public:
    int hIndex(vector<int>& citations) {//binary search
        
        //  the main idea is to find the least number #mid# satisfying: citations[mid]>=size-mid
        //  then the answer would be (size-mid)
        const int size=citations.size(); //define constant value using CONST to save running time
        int low=0,high=size,mid;
        while(low<high){
            mid=low+(high-low)/2; //instead of mid=(low+high)/2 to save running time
            if(citations[mid]>=size-mid){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return size-low;
    }
};