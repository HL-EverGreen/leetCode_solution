// Design & array & binary search
// time complexity: O(1) for Solution(), O(logn) for pickIndex()
// space complexity: O(n)
// 132ms, beats 90%

class Solution {
public:
    Solution(vector<int>& w) {
        for(const auto& i : w) s.push_back(s.empty() ? i : s.back() + i);
    }
    
    int pickIndex() {
        int i = rand() % s.back();
        return upper_bound(s.begin(), s.end(), i) - s.begin();
    }
private:
    vector<int> s;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */