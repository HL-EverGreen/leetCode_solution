class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.length()==1){
            if(num[0]=='0'||num[0]=='1'||num[0]=='8')
                return true;
            else return false;
        }
        if(num.length()==0) return true;
        if((num[0]=='0' && num[num.length()-1]=='0')
          || (num[0]=='1' && num[num.length()-1]=='1')
          || (num[0]=='8' && num[num.length()-1]=='8')
          || (num[0]=='6' && num[num.length()-1]=='9')
          || (num[0]=='9' && num[num.length()-1]=='6'))
            return isStrobogrammatic(num.substr(1,num.length()-2));
        else return false;
        
    //or can use map
    /*
        map<char, char> mp{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for(int i = 0; i < num.size(); i++){
            if(mp[num[i]] != num[num.size() - i - 1])  return false;
        }
        return true;
    */
    }
};