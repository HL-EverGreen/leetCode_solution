class Solution {
public:
    string getPermutation(int n, int k) { //permutation
        //total number of permutation: n!
        //number of permutation start with '1':(n-1)!
        //number of permutation start with '2':(n-1)!
        //so we can calculate the number by divide k by n!(or n-1, n-2 ....)
        int pTable=n,temp;
        vector<char> num(n,'1');
        string res;
        for(int i=1;i<n;i++){
            pTable*=i;
            num[i]=num[i-1]+1;
        }
        while(n>0){
            pTable/=n;
            temp=(k-1)/pTable;
            res+=num[temp];
            num.erase(num.begin()+temp);
            k-=temp*pTable;
            n--;
        }
        return res;
    }
};