class Solution {
public:
    int numWays(int n, int k) {//dp
        if(n<=1 || k==0) return n*k;
        int dp1=k*(k-1),dp2=k,tmp; //dp1:一次迭代中最后两个元素不同的组合数
                                   //dp2:一次迭代中最后两个元素相同的组合数
                                   //更新方式: new_dp1=(k-1)(dp1+dp2)
                                   //         new_dp2=dp1
        for(int i=2;i<n;i++){
            tmp=dp1;
            dp1=(k-1)*(dp1+dp2);
            dp2=tmp;
        }
        return dp1+dp2;
    }
};