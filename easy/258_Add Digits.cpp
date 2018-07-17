class Solution {
public:
    int addDigits(int num) {
        int res=0;
        while(num/10!=0){
            res+=num%10;
            num/=10;
        }
        res+=num;
        if(res/10==0)return res;
        else return addDigits(res);
    }
};