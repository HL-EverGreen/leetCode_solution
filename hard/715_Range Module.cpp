// treemap
// time complexity: O(logn) for addRange and removeRange in best case or averate, O(n) in worst case
// space complexity: O(n)
// 276ms, beats 73.09%

// Main idea:
// Use hashmap to store the interval whose key is left, and value is right.
// Use binary search to find specific boundary and do operation.
// ***Notice: Can use both lower_bound of left and right!! See method 2 below

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = db.lower_bound(left);
        auto tmp = it;
        stack<int> s;
        while(tmp != db.end() && tmp->first <= right) { // Connect in right direction
            right = max(right, tmp->second);
            s.push(tmp->first);
            ++tmp;
        }
        while(it != db.begin()) {   // Connect in left direction
            --it;
            if(it->second >= left) {
                left = min(left, it->first);
                right = max(right, it->second);
                s.push(it->first);
            } else break;
        }
        while(!s.empty()) {
            db.erase(s.top());
            s.pop();
        }
        db[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = db.upper_bound(left);
        if(it != db.begin()) {
            --it;
            if(it->first <= left && it->second >= right) return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        stack<int> s;
        auto it = db.lower_bound(left);
        auto tmp = it;
        while(tmp != db.end() && tmp->second <= right) {    // Check in right direction
            s.push(tmp->first);
            ++tmp;
        }
        if(tmp != db.end() && tmp->first < right && tmp->second > right) {
            s.push(tmp->first);
            db[right] = tmp->second;
        }
        
        if(it != db.begin()) {  // Check left
            --it;
            if(it->second > left) {
                if(it->second > right) {
                    db[right] = it->second;   
                }
                it->second = left;
            }
        }
        while(!s.empty()) {
            db.erase(s.top());
            s.pop();
        }
    }
private:
    map<int, int> db;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

// Method 2
// Use both the left and right when binary search
class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l=mp.upper_bound(left);
        auto r=mp.upper_bound(right);
        if(l!=mp.begin()){
            l--;
            if(l->second<left){
                l++;
            }
        }
        
        if(l!=r){
            left=min(left,l->first);
            right=max(right,(--r)->second);
            mp.erase(l,++r);
        }
        mp[left]=right;
    }
    
    bool queryRange(int left, int right) {
        auto l=mp.upper_bound(left);
        if(l==mp.begin()|| (--l)->second<right){
            return false;
        }
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l=mp.upper_bound(left);
        auto r=mp.upper_bound(right);
        if(l!=mp.begin()){
            l--;
            if(l->second<=left){
                l++;
            }
        }
        
        if(l==r){
            return;
        }
        
        int l1=min(left,l->first);
        int r1=max(right,(--r)->second);
        mp.erase(l,++r);
        if(l1<left){
            mp[l1]=left;
        }
        if(r1>right){
            mp[right]=r1;
        }
    }
    map<int,int> mp;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */