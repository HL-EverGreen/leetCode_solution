class Solution {
public:
    int nthUglyNumber(int n) {//dp
        if(n==0) return -1;
        vector<int> res(n,0);
        res[0]=1;
        int k2=0,k3=0,k5=0;
        for(int i=1;i<n;i++){
            res[i]=min(res[k2]*2,min(res[k3]*3,res[k5]*5));
            if(res[i]==res[k2]*2) k2++;
            if(res[i]==res[k3]*3) k3++;
            if(res[i]==res[k5]*5) k5++;
        }
        return res[n-1];
    }   
};