class Solution {
public:
    int hIndex(vector<int>& citations) {
        // array
        // time complexity: O(nlogn), space complexity: O(1)
        // 0ms, beats 100% (use binary search can be faster, see method 2)
        
        int size = citations.size();
        sort(citations.begin(), citations.end());
        for(int i = size - 1; i >= 0; i--) {
            if(citations[i] >= size - i && (i == 0 || citations[i - 1] <= size - i)) return size - i;
        }
        return 0;


        // method 2
        // Binary search, H-Index II solution
        /*
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
        */


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
    }
};