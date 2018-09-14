class Solution {
public:
    int countPrimes(int n) { //prime number
        if(n<=2) return 0;
        vector<bool> flg(n,false);
        int sum=1, upper=sqrt(n);
        for(int i=3;i<n;i+=2){  //only check odd number
            if(!flg[i]){
                sum++;
                if(i>upper) continue;  //avoid overflow
                for(int j=i*i;j<n;j+=2*i) flg[j]=true;
            }
        }
        return sum;
    }
};