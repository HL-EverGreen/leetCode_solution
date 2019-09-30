class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // union find
        // time complexity: O(n), space complexity: O(1) -> O(26)
        // 0ms, beats 100%
        
        // Main idea:
        // Straight union found solution in two pass:
        //   1) Check all "==" equations and setup uf array value
        //   2) Check all "!=" equations and check whether the uf value is the same, if same return false.
        
        vector<int> uf(26, 0);
        for(int i = 1; i < 26; ++i) uf[i] = i;
        
        // Construct uf array
        for(auto& eq : equations) {
            if(eq.find("==") != string::npos) uf[find(uf, eq[0] - 'a')] = find(uf, eq[3] - 'a');
        }
        
        // Check consistency
        for(auto& eq : equations) {
            if(eq.find("!=") != string::npos && find(uf, eq[0] - 'a') == find(uf, eq[3] - 'a')) return false;
        }
        return true;
    }
    
    // Find function for UF. Set descendant's value to its foremost predecessor
    int find(vector<int>& uf, int i) {
        if(uf[i] != i) {
            uf[i] = find(uf, uf[i]);
        }
        return uf[i];
    }
};