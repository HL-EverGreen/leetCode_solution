class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // array
        // time complexity: O(nlogn), space complexity: O(1)
        // 40ms, beats 90.82%
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int res = 0;
        for(int gi = 0, si = 0; gi < g.size() && si < s.size();) {
            if(s[si] >= g[gi]) {        // can assign this cookie
                res++;
                gi++;
            }
            si++;
        }
        return res;
        
    }
};