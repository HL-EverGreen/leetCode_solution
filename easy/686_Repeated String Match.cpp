class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // string match
        
        // method 1
        // KMP
        // time complexity: O(m + n), space complexity: O(n)
        
        // Main idea:
        // Construct KMP next vector, and when compare B with A, if B[i] miss,
        // directly set j to kmp[j - 1], so that in next comparison, it can directly
        // skip matched common substring (since kmp[j - 1] means length of common prefix and suffix in B[0~j-1],
        // so previously matched B[j] is also contained before new j = kmp[j - 1]. So that can skip already matched length)

        // Construct `next` array for KMP
        int m = A.length(), n = B.length();
        vector<int> kmp(n, 0);
        for(int end = 1, start = 0; end < n;) {
            if(B[start] == B[end]) kmp[end++] = ++start;
            else if(start == 0) ++end;      // Can't match for current suffix, continue to try next
            else start = kmp[start - 1];    // Not match, try next shorter prefix to match suffix
        }
        
        // for(int i = 0; i < n; ++i) cout << kmp[i] << "|";
        // cout<<endl;
        for(int i = 0, j = 0; i < m; ++i) {
            while(j < n && A[(i + j) % m] == B[j]) ++j;
            if(j == n) return ceil((float)(i + j) / m);   
            if(j) j = kmp[j - 1];           // Decrease j to former suitable position, 
                                            // directly jump to next comparison position
                                            // by skipping smaller common substring
        }
        return -1;
        
        // method 2
        // Another version of normal match
        // time complexity: O(mn), space complexity: O(1)
        // 12ms, beats 83.01%
        
        string cur = A;
        int m = A.length(), n = B.length(), limit = n / m + 2;
        for (int rep = 1; rep <= limit; ++rep, cur.append(A))
            if (cur.find(B) != string::npos) return rep;
        return -1;
        
        // method 3
        // Normal string match
        // time complexity: O(mn), space complexity: O(1)
        // 352ms, beats 21.56%
        
        // Straight forward, from every start index at A, try to match B.
        int m = A.length(), n = B.length();
        for(int i = 0, j = 0; i < m; ++i) {
            for(j = 0; B[j] == A[(i + j) % m]; ++j);
            if(j == n) return (i + j + m - 1) / m;
        }
        return -1;
    }
};