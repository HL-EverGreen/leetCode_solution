class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        // DP & tree map
        // time complexity: O(nlogn), space complexity: O(n)
        // 88ms, beats 87.72%
        
        // Main idea:
        // higher[i] and lower[i] represent whether start from index i, can
        //   reach end point by jumping higher of lower (odd/even jump)
        // The end point's higher[n-1] and lower[n-1] are both 1 since it 
        //   has already reached the end
        // The other is: if jump to higher node && higher node's lower[i] == 1,
        //   then this node's higher[i] == 1.
        
        int n  = A.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            // Since map is ordered, and element is added gradually,
            // we can use lower_bound and (--upper_bound) to find
            // the higher jump node and the lower jump node
            auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);
            if (hi != map.end()) higher[i] = lower[hi->second];
            if (lo != map.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) res++;
            map[A[i]] = i;              // Added current node into map
        }
        return res;
    }
    
};