class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {//bit_operation
        int s_size=s.size();
        vector<string> res;
        bitset<1<<20> S1,S2;  //S1 stores feature value of the 10-letter-long string which appears at least once
                              //S2 stores feature value of the 10-letter-long string which has been pushed to the result
        if(s_size<=10) return res;
        int val=0;
        for(int i=0;i<10;i++) val=(val<<2) | charToInt(s[i]); //calculate the first 10-letter-long string's feature value
        S1.set(val);
        int mask=(1<<20)-1;  //twenty bit long full of 1, used to eliminate the past char(out of 10)
        for(int i=10;i<s_size;i++){
            val=((val<<2) & mask) | charToInt(s[i]); //update the 10-letter-long string and its feature value
            if(S2[val]) continue;
            if(S1[val]){
                res.push_back(s.substr(i-9,10));
                S2.set(val);
            }else S1.set(val);
        }
        return res;
    }
    
    int charToInt(char ch){  //change char into '00','01','10','11'
        switch(ch){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }
};