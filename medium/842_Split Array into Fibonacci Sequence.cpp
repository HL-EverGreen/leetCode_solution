class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        // string & DFS
        // 0ms, beats 100%
        
        // divide into two cases: 1) leading with 0, so try single 0 in solution (can't have any number with leading 0 so 0 must be used singly)
        //                        2) not leading with 0, try max to next 10-length digit (length of INT_MAX)
        vector<int> res;
        findFS(S, res, 0);
        return res;
    }
    
    bool findFS(string S, vector<int>& res, int start) {
        if(start == S.length() && res.size() >= 3) return true;
        
        // Since '0' in beginning is not allowed therefore if the current char is '0'
        // then we can use it alone only and cannot extend it by adding more chars at the back.
        // Otherwise we make take upto 10 chars (length of INT_MAX)
        int num = (S[start] == '0' ? 1 : 10);
        for(int i = 1; i <= num && i + start <= S.size(); i++) {
            long long next_num = stoll(S.substr(start, i));
            if(next_num > INT_MAX) return false;
            int size = res.size();
            if(size > 2 && res[size - 2] + res[size - 1] < next_num) return false;              // If fibonacci property is not satisfied then we cannot get a solution
            if(size < 2 || res[size - 2] + res[size - 1] == next_num) {
                res.push_back(next_num);
                if(findFS(S, res, i + start)) return true;
                res.pop_back();
            }
        }
        return false;
    }
};