class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // string & bitset
        // time complexity: O(n), space complexity: O(1 << 20)
        // 4ms, beats 100%
        
        int size = s.length();
        vector<string> res;
        if(size <= 10) return res;
        bitset<1 << 20> S1, S2;             // S1 stores feature value of the 10-letter-long string which appears at least once
                                            // S2 stores feature value of the 10-letter-long string which has been pushed to the result
        int val = 0, mask = (1 << 20) - 1;  // mask : 20 bit full of 1, used to only keep 20 bit data
        for(int i = 0; i < 10; i++) val = (val << 2) | charToInt(s[i]);     // calculate the first 10-letter-long string's feature value
        S1.set(val);
        for(int i = 10; i < size; i++) {
            val = ((val << 2) & mask) | charToInt(s[i]);                    // update the 10-letter-long string and its feature value    
            if(S2[val]) continue;
            if(S1[val]) {
                res.push_back(s.substr(i - 9, 10));
                S2.set(val);
            } else S1.set(val);
        }
        return res;
    }
    
    int charToInt(char ch) {        //change char into '00','01','10','11'
        switch(ch) {
            case 'A' : return 0;
            case 'C' : return 1;
            case 'G' : return 2;
            case 'T' : return 3;
        }
        return -1;
    }
};