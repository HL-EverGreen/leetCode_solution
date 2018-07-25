class Solution {
public:
    vector<int> grayCode(int n) {//iteration maybe faster
        vector<int> res;
        vector<int> temp;
        
        if(n==0){
            res.push_back(0);
            return res;
        }
        
        temp=grayCode(n-1);
        res=temp;
        reverse(temp.begin(),temp.end());
        //for(int i=0;i<temp.size();i++)
        //    temp[i]=temp[i]+pow(2,n-1);
        for(auto &num:temp)
            num+=pow(2,n-1);
        res.insert(res.end(),temp.begin(),temp.end());
        return res;
    }
};