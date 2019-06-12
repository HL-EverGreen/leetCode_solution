class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // array & priority queue
        // time complexity: O(nlogn), space complexity: O(n)
        // 16ms, beats 93.98%
        
        // Main idea:
        // Sort the original array, while record each element's original position.
        // This can be done using priority queue, as well as map

        priority_queue<pair<int, int>> pq;          // <value, pos>
        int size = nums.size(), count = 1;
        vector<string> res(size);
        
        for(int i = 0; i < size; i++) {
            pq.push({nums[i], i});
        }
        
        while(!pq.empty()) {
            if(count == 1) { res[pq.top().second] = "Gold Medal"; }
            else if(count == 2) { res[pq.top().second] = "Silver Medal"; }
            else if(count == 3) { res[pq.top().second] = "Bronze Medal"; }
            else { res[pq.top().second] = to_string(count); }
            count++;
            pq.pop();
        }
        return res;
    }
};