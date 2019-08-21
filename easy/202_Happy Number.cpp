class Solution {
public:
    bool isHappy(int n) {
        // number
        // 0ms, beats 100%
        
        // Use hash table to record seen number
        unordered_map<int, int> myMap;
        int temp;
        while(n != 1){
            // judge if there exists a circle
            if(myMap.find(n) != myMap.end()) return false;
            myMap[n] = 1;
            temp = 0;
            while(n){
                temp += pow(n % 10, 2);
                n /= 10;
            }
            n = temp;
        }
        return true;
    }
};