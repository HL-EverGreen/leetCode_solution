class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // array
        // time complexity: O(nk), k is the A[0].length(), space complexity: O(n)
        // 8ms, beats 98.93%
        
        // check word by word, if find A[i - 1][c] > A[i][c], insert c into dc and reset i
        unordered_set<int> dc;
        for(int i = 1; i < A.size(); i++) {
            for(int c = 0; c < A[0].length(); c++) {
                if(dc.count(c) || A[i - 1][c] == A[i][c]) continue;
                if(A[i - 1][c] > A[i][c]) {
                    dc.insert(c);
                    i = 0;                           // since c will +1 in the end of the loop, so would be 1 at next loop
                }
                break;                               // have compared two words, go to next or go to start again
            }
        }
        return dc.size();
    }
};