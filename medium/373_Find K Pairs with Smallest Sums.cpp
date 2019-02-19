class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // array & priority queue
        // time complexity: O(min(k, mn)log(min(k, mn))), space complexity: O(min(k, mn))
        // 16ms, beats 100%
        
        vector<pair<int, int>> res;
        if(nums1.empty() || nums2.empty() || k <= 0) return res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push({0, 0});
        while(k-- > 0 && pq.size()) {
            auto cur = pq.top();
            pq.pop();
            res.push_back({nums1[cur.first], nums2[cur.second]});
            if(cur.first < nums1.size() - 1)
                pq.push({cur.first + 1, cur.second});
            if(cur.first == 0 && cur.second < nums2.size() - 1)                             // cur.second can +1 only when cur.first == 0, to avoid push duplicate elements
                pq.push({cur.first, cur.second + 1});
        }
        return res;
    }
};