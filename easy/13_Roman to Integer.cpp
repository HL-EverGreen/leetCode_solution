class Solution {
public:
    int romanToInt(string s) {
        map<char,int> myMap={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int res=0;
        for(int i=0;i<s.length()-1;i++){
            if(myMap[s[i]]<myMap[s[i+1]])
                res-=myMap[s[i]];
            else
                res+=myMap[s[i]];
        }
        res+=myMap[s[s.length()-1]];
        return res;
    }
};