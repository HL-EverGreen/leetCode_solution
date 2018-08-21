class Solution {
public:
    int hIndex(vector<int>& citations) {
        //traditional math method
        /*
        int N = citations.size();
        vector<int> counts(N+1, 0);
        for (int c : citations) {
            if (c >= N) counts[N]++;
            else counts[c]++;
        }
        
        int nomorethani = 0;
        for (int i=0; i<=N; i++) {
            if (nomorethani<=N-i && N-i-counts[i]<=nomorethani) return i;
            nomorethani += counts[i];
        }
        return -1;
        */
        
        //H-Index II solution, sort first
        const int size=citations.size(); //define constant value using CONST to save running time
        if(size==0) return 0;
        sort(citations.begin(),citations.end());
        int low=0,high=size,mid;
        while(low<high){
            mid=low+(high-low)/2; //instead of mid=(low+high)/2 to save running time
            if(citations[mid]>=size-mid){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return size-low;
    }
};