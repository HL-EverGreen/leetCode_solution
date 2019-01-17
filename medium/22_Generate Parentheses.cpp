class Solution {
public:
    // string
    
    // method 1
    // recursive, kind of DFS, top-down
    // 0ms, beats 100%
    
    // left_num : number of "(" remained
    // right_num : number of ")" remained
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        geneParen(res, str, n, 0);
        return res;
    }
    
    void geneParen(vector<string>& res, string str, int left_num, int right_num) {
        if(left_num == 0 && right_num == 0) {
            res.push_back(str);
            return;
        }
        if(left_num > 0) { geneParen(res, str + "(", left_num - 1, right_num + 1); }
        if(right_num > 0) { geneParen(res, str + ")", left_num, right_num - 1); }
    }
    
    
    // method 2
    // recursive, top-down with memorization
    // 0ms, beats 100%
    /*
    unordered_map<int, vector<string>> paren;
    vector<string> generateParenthesis(int n) {
        if(paren.find(n) != paren.end()) { return paren[n]; }
        vector<string> cur_p;
        if(n == 0) { cur_p.push_back(""); }
        
        for(int c = 0; c < n; c++) {                                    // calculate all possible combinations
            vector<string> left = generateParenthesis(c);
            vector<string> right = generateParenthesis(n - 1 - c);
            for(int i = 0; i < left.size(); i++) {
                for(int j = 0; j < right.size(); j++) {
                    cur_p.push_back("(" + left[i] + ")" + right[j]);
                }
            }
        }
        paren[n] = cur_p;
        return paren[n];
    }
    */
};