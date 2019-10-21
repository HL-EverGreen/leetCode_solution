// Design & map & array
// time complexity: O(1) for insert(), remove() and getRandom()
// space complexity: O(n)
// 52ms, beats 96.07%

// Main idea:
// Keep all number in nums, so getRandom get directly random a value in range.
// In order to achieve O(1) remove time, when remove a value, we need to move the
// last element to the place where removed value is.
// So we need to record index info in map about each numbers in nums.
// We also need store info in nums to find corresponding index in map to achieve O(1) time
// when move last element (modify index of last element in map to removed value's index, so find
// index in map to store this message in O(1) time).

// So we use the following data structure:
// m: unordered_map<int, vector<int>>, key is val, value is indices where the val appears in nums.
// Nums: vector<pair<int, int>>: {val, index into m[val]}.
// There is a relationship between nums and m: m[nums[i].first][nums[i].second] == i;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();
        
        m[val].push_back(nums.size());              // Update position information in both data structure
        nums.emplace_back(val, m[val].size() - 1);
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // May should add more code to check whether nums is empty
        
        if(m.find(val) != m.end()) {
            auto last = nums.back();
            nums[m[val].back()] = last;                  // Replace removed val with last element
            m[last.first][last.second] = m[val].back();  // Modify `last` index info stored in map
            nums.pop_back();                             // Remove last element (already moved to another place)
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);             // No current element anymore
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
