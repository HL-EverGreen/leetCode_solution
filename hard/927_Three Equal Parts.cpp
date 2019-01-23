class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 24ms, beats 96.91%
        
        // First, compute number of 1
        // Then find start index of each sequence begin with 1
        // Compare them repeatly
        
        // calculate number of 1
        int count1 = 0;
        for(auto a : A) {
            if(a == 1) count1++;
        }
        if(count1 == 0) return {0, A.size() - 1};
        if(count1 % 3 != 0) return {-1, -1};
        
        // get start index of three sequences
        int k = count1 / 3, cnt = 0, start = -1, mid = -1, end = -1;
        for(int i = 0; i < A.size(); i++) {
            cnt += A[i];
            if(cnt == 1 && start == -1) start = i;
            if(cnt == k + 1 && mid == -1) mid = i;
            else if(cnt == 2 * k + 1 && end == -1) end = i;
        }
        
        // compare these three sequences
        while(end < A.size()) {
            if(A[start] == A[mid] && A[mid] == A[end]) { start++; mid++; end++; }
            else return {-1, -1};
        }
        
        return {start - 1, mid};
    }
};