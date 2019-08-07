class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // geometry & hash table & set
        // time complexity: O(n^2) or (n^1.5), space complexity: O(n), n is the number of points
        // 140ms, beats 77.61%
        
        // Group all points according to their x coords, use set to store this points.
        // Implement intersection operation between two sets, find common y coords.
        // Since set is in order, we just need to compare res with `width` * (same_y[k] - same_y[k - 1])
        
        // new functions:
        // set_intersection: Constructs a sorted range beginning in the location pointed by OutputIterator with the set intersection of the two sorted ranges [first1,last1) and [first2,last2).
        // inserter: Constructs an insert iterator that inserts new elements into x in successive locations starting at the position pointed by it.
        // next(iterator, n): Returns an iterator pointing to the element that it would be pointing to if advanced n positions.
        
        unordered_map<int, set<int>> x;
        int res = INT_MAX;
        for(auto p : points) { x[p[0]].insert(p[1]); }
        
        for(auto i = x.begin(); i != x.end(); i++) {
            if(i->second.size() < 2) { continue; }
            for(auto j = next(i); j != x.end(); j++) {
                if(j->second.size() < 2) { continue; }
                vector<int> y;
                set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), inserter(y, y.begin()));   // Or back_inserter(y)
                for(int k = 1; k < y.size(); k++) {
                    res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};