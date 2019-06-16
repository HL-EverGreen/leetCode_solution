class MyCalendar {
public:
    // binary tree & set
    // book() time complexity: O(logn)
    // space complexity: O(n)
    // 104ms, beats 88.71%
    
    // Main idea:
    // Use set check function to determine whther exists equal element.
    // Here, we define equal elements as overlapping elements.
    // So, we can directly use find to find if overlapped.
    // Amazing!!!
    set<pair<int, int>, bool(*)(const pair<int, int>&, const pair<int, int>&)> s;
    MyCalendar() {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second <= b.first;
        };
        s = set<pair<int, int>, bool(*)(const pair<int, int>&, const pair<int, int>&)>(cmp);
    }
    
    bool book(int start, int end) {
        auto p = make_pair(start, end);
        if(s.find(p) == s.end()) {
            s.insert(p);
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */