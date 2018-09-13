class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() { //map
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        map[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto m:map){
            int fi=m.first;
            int se=value-fi;
            if((fi==se && m.second>1) || (fi!=se && map.count(se))) return true;  // use map.count() instead of map.find(se)!=map.end()
        }
        return false;
    }
    
private:
    unordered_map<int,int> map;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */