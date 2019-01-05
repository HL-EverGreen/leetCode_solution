class Solution {
public:
    int nthUglyNumber(int n) {
        // dynamic programming
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 97.6%
        
        // each round compute next ugly number and its computing way (if *2, then k2++, if *3 then k3++, if *5 then k5++)
        if(n <= 0) { return 0; }
        vector<int> res(n, 1);
        int k2 = 0, k3 = 0, k5 = 0;
        
        for(int i = 1; i < n; i++) {
            res[i] = min(res[k2] * 2, min(res[k3] * 3, res[k5] * 5));
            
            // can't write in else if style, since res[k2] * 2, res[k3] * 3 and res[k5] * 5 may be duplicated
            // so must enter every if in each loop
            if(res[i] == res[k2] * 2) { k2++; }
            if(res[i] == res[k3] * 3) { k3++; }
            if(res[i] == res[k5] * 5) { k5++; }
        }
        return res[n - 1];
    }
};