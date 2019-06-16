class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // priority queue & k list
        // time complexity: O(nlogk), k is the number of list, n is the estimation of number of elements in each list
        // space complexity: O(nk)
        // 56ms, beats 91.93%

        // Main idea:
        // Kind of like merge K list. Always track set consisted of first k elements from each list.
        // Each time find smallest elements, and replace it with next element from that list.
        // And dynamically update lo and hi.
        typedef vector<int>::iterator vi;
        typedef pair<vi, vi> pvi;
       
        // Small heap
        struct cmp {
            bool operator()(pvi& p1, pvi& p2) {
                return *(p1.first) > *(p2.first);
            }
        };
        
        priority_queue<pvi, vector<pvi>, cmp> pq;
        int lo = INT_MAX, hi = INT_MIN;

        // Use all head element in each list, and get lowest and highest of them
        for(auto& num : nums) {
            lo = min(lo, num[0]);
            hi = max(hi, num[0]);
            pq.push({num.begin(), num.end()});
        }
    
        vector<int> res = {lo, hi};
        
        while(true) {
            auto p = pq.top();
            pq.pop();
            /* One of lists has no more elements */
            if(++p.first == p.second) { break; }
            /* Update with next element from that list */
            pq.push(p);
            /* Update lo and hi for current set */
            lo = *(pq.top().first);
            hi = max(hi, *(p.first));
            if(hi - lo < res[1] - res[0]) {
                res = {lo, hi};
            }
        }
        return res;
    }
};