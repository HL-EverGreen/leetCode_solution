class Solution {
public:
    int compareVersion(string version1, string version2) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // compute and compare each number between dots respectly
        int n1 = version1.length(), n2 = version2.length();
        for(int i = 0, j = 0; i < n1 || j < n2; i++, j++) {
            int num1 = 0, num2 = 0;
            
            // compute current version number for VERSION1
            while(i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // compute current version number for VERSION2
            while(j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // compare the version number
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
        }
        return 0;
    }
};