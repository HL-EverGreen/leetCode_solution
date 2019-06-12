class Solution {
public:
    string orderlyQueue(string S, int K) {
        // string
        // time complexity: O(nlogn), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // If K > 1, then we can 1) rotate the whole string 2) rotate string start at 1
        // So we can use bubble sort to sort the whole string.
        // So when K > 1, return sorted string.
        // For K = 1: try all combinations.
        if(K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        
        string res = S;
        int size = S.length();
        for(int i = 0; i < size; i++) {
            res = min(res, S.substr(i) + S.substr(0, i));
        }
        return res;
    }
};