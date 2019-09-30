class Solution {
public:
    typedef vector<int>::iterator iter;
    int reversePairs(vector<int>& nums) {
        // merge sort & array pair pattern
        // time complexity: O(nlogn), space complexity: O(1)
        // 320ms, beats 60.42%
        
        // Similar to LC 315, use merge sort to find specified pairs in the array.
        
        // Can also use BST (still similar to LC 315), store counts that nodes smaller than current node.
        // When insert new node, first find node < (val/2) by searching with node(val/2). Then insert node(val).
        
        int N = nums.size();
        if(N <= 1) return 0;
        int res = 0;
        countAndMerge(nums.begin(), nums.end(), res);
        return res;
    }
    
    /* Count res and merge two sorted subarray */
    void countAndMerge(iter begin, iter end, int& res) {
        if(end - begin <= 1) return;
        iter mid = begin + (end - begin) / 2;
        countAndMerge(begin, mid, res);
        countAndMerge(mid, end, res);
        
        for(iter i = begin, j = mid; i != mid; ++i) {
            while(j < end && ceil((*i) / 2.0) > (*j)) ++j;
            res += j - mid;
        }
        inplace_merge(begin, mid, end);
    }
};