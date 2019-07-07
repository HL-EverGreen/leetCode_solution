class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 83.5%
        
        // Main idea:
        // Use hash table to record each elem's position in B
        // Inorder to handle duplicate, A pick last pos in vector, and pop last elem in vector
        
        unordered_map<int, vector<int>> m;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            m[B[i]].push_back(i);
        }
        
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = m[A[i]].back();
            m[A[i]].pop_back();                         // Pop used position
        }
        return res;
    }
};