class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {//merge two sorted array
        int index_n1=m-1, index_n2=n-1, tog=m+n-1;
        while(index_n2>=0){ //add from end
            nums1[tog--]=index_n1>=0 && nums1[index_n1]>nums2[index_n2]?nums1[index_n1--]:nums2[index_n2--];
        }
    }
};