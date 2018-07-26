class Solution {
public:
    bool isHappy(int n) {
        map<int,int> myMap;
        int temp;
        while(n!=1){
            if(myMap.find(n)!=myMap.end()) // judge if there exists a circle
                return false;
            myMap[n]=1;
            temp=0;
            while(n/10!=0){
                temp+=pow(n%10,2);
                n/=10;
            }
            temp+=pow(n,2);
            n=temp;
        }
        return true;
    }
};