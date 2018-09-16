class Solution {
public:
    int candy(vector<int>& ratings) {  //allocate_number
        int size=ratings.size(), res=0;
        if(size<2) return size;
        vector<int> num(size,1);
        for(int i=1;i<size;i++)                             //from left
            if(ratings[i]>ratings[i-1]) num[i]=num[i-1]+1;
        for(int i=size-2;i>=0;i--)                          //from right
            if(ratings[i]>ratings[i+1]) num[i]=max(num[i],num[i+1]+1);
        for(auto n:num) res+=n;
        return res;
    }
};