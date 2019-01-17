class Solution {
public:
    string intToRoman(int num) {
        // string
        // time complexity: O(1), space complexity: O(1)
        // 44ms, beats 95.19%
        
        // divide by number unit repeatly
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        for(int i = 0; i < 13; i++) {
            int temp = num / number[i];
            num -= temp * number[i];
            for(int j = 0; j < temp; j++) res += roman[i];
        }
        return res;
        
        
        //use stack
        /*
        map<int,string> myMap={
            {1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"},
            {10,"X"},{20,"XX"},{30,"XXX"},{40,"XL"},{50,"L"},{60,"LX"},{70,"LXX"},{80,"LXXX"},{90,"XC"},
            {100,"C"},{200,"CC"},{300,"CCC"},{400,"CD"},{500,"D"},{600,"DC"},{700,"DCC"},{800,"DCCC"},{900,"CM"},
            {1000,"M"},{2000,"MM"},{3000,"MMM"}
        };
        stack<int> s;
        string res;
        int iter=1;
        int number;
        while(num/10!=0){
            s.push(num%10*iter);
            num/=10;
            iter*=10;
        }
        s.push(num*iter);
        while(!s.empty()){
            number=s.top();
            res+=myMap[number];
            s.pop();
        }
        return res;
        */
    }
};