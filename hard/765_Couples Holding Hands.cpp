class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // array & greedy
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // two pass:
        // first pass record each person's position
        // second pass swap people
        vector<int> pos(row.size(), -1);
        int res = 0;
        for(int i = 0; i < row.size(); i++) pos[row[i]] = i;
        for(int i = 0; i < row.size(); i += 2) {
            int myCouple = (row[i] & 1 == 1 ? row[i] - 1 : row[i] + 1);     // compute my couple's id
            int neighbor = row[i + 1]; 
            if(neighbor != myCouple) {                                      // if neighbor is not couple, swap neighbor and couple
                res++;
                row[pos[myCouple]] = neighbor;
                pos[neighbor] = pos[myCouple];                              // no need to update couple's position
            }
        }
        return res;
    }
};