class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // array
        // time complexity: O(nlogn), space complexity: O(n)
        // 28ms, beats 98.72%
        
        // 先插高个，个子相同先插second小的
        auto comp = [](pair<int, int>& p1, pair<int, int>& p2) { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        sort(people.begin(), people.end(), comp);
        
        vector<pair<int, int>> res;
        for(auto& p : people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};