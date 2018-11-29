class Solution {
public:
    int compareVersion(string version1, string version2) {
        // string
        // time complexity: O(n), n is the shorter string's length
        
        int idx1 = 0, idx2 = 0;
        int n1 = version1.length(), n2 = version2.length();
        
        while(idx1 < n1 || idx2 < n2) {
            int num1 = 0, num2 = 0;
            
            // compute current version number for VERSION1
            while(idx1 < n1 && version1[idx1] != '.') {
                num1 = 10* num1 + (version1[idx1] - '0');
                idx1++;
            }
            
            // compute current version number for VERSION2
            while(idx2 < n2 && version2[idx2] != '.') {
                num2 = 10 * num2 + (version2[idx2] - '0');
                idx2++;
            }
            
            // compare the version number
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            
            idx1++; idx2++;
        }
        return 0;
    }
};