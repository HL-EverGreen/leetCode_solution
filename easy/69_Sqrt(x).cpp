class Solution {
public:
    int mySqrt(int x) {//binary search
        int low=1, high=x, mid;
        if(x<2) return x;
        while(low<=high){
            mid=low+(high-low)/2;
            if(pow(mid,2)==x) return mid;
            else if(pow(mid,2)<x) low=mid+1;
            else high=mid-1;
        }
        return high;
        
        //Newton-Raphson Method
        /*
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
        */
    }
};