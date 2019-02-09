class RandomizedSet {
public:
    /** Initialize your data structure here. */
    // hash table & vector
    // all operations time complexity: O(1)
    // 64ms, beats 100%
    
    // Main idea: 
    // 1. Use hash map to store elements, achieve insert and remove O(1)
    // 2. Use vector to achieve getRandom operation
    // 3. When delete, erase element in hash table, and pop vector's last element while updating that element's information in val's position in vector and hash table
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash_nums.find(val) != hash_nums.end()) return false;
        nums.push_back(val);
        hash_nums[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash_nums.find(val) == hash_nums.end()) return false;
        int back = nums.back();
        hash_nums[back] = hash_nums[val];
        nums[hash_nums[val]] = back;
        hash_nums.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    unordered_map<int, int> hash_nums;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */