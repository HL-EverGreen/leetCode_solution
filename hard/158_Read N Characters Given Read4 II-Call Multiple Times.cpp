// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        // Design
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Contain a internal buf4 and i4 to indicate current read index.
        // And use n4 to present current max readable index.
        // If i4 == n4, read all local data, need to call read4 again.
        // If n4 == 0 after calling read4, then read at the end
        
        int i = 0;
        while(i < n) {
            if(i4 == n4) {  // Read all local buffered data
                i4 = 0;
                n4 = read4(buf4);
                if(!n4) break;      // Read at end
            }
            buf[i++] = buf4[i4++];
        }
        return i;
    }
private:
    char buf4[4];
    int i4 = 0, n4 = 0;
};