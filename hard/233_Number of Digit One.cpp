class Solution {
public:
    int countDigitOne(int n) { //number
        int ans=0;
        if(n<=0) return 0;
        if(n<=9) return 1;
        unordered_map<int,int> mp;
        mp[9]=1;
        for(int i=9;i<=(INT_MAX-9)/10;i=10*i+9){
            mp[10*i+9]=10*mp[i]+i+1;
        }
        int tmp=n,divisor=1;
        while(tmp/10){
            tmp/=10;
            divisor*=10;
        }
        ans+=(n/divisor)*mp[divisor-1];
        ans+=(n/divisor>1)?divisor:0;
        ans+=(n/divisor==1)?n-divisor+1:0;
        ans+=countDigitOne(n%divisor);
        return ans;
        
        //iteration solution
        /*
        int res = 0, level = 1;
        int low = 0;
        while (n >= level)
        {
            int g = (n / level) % 10;
            if (g < 1)
            {
                res += (n / level) / 10 * level;
            }else if (g == 1)
            {
                res += (n / level) / 10 * level + n % level + 1;
            }else
            {
                res += (n / level) / 10 * level + level;
            }
            if (n / 10 < level) break;
            level *= 10;
        }
        return res;
        */
    }
};