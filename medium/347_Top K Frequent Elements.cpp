class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // array & max k
        
        // priority queue
        // time complexity: O(nlogk)
        // 20ms, beats 100%

        unordered_map<int, int> counts;
        priority_queue<int, vector<int>, greater<int>> max_k;
        
        for(auto i : nums) counts[i]++;
        for(auto& i : counts) {
            max_k.push(i.second);
            while(max_k.size() > k) max_k.pop();
        }
        
        vector<int> res;
        for(auto& i : counts) {
            if(i.second >= max_k.top()) res.push_back(i.first);
        }
        return res;
        
        // bucket sort
        // time complexity: O(n)
        // 24ms, beats 76.92%
        /*
        unordered_map<int, int> counts;
        for(auto i : nums) counts[i]++;
        
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& i : counts)
            buckets[i.second].push_back(i.first);
        
        reverse(buckets.begin(), buckets.end());
        
        vector<int> res;
        for(auto& bucket : buckets) {
            for(auto i : bucket) {
                res.push_back(i);
                if(res.size() == k) return res;
            }
        }
        return res;
        */
    }
};