// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {        
        int res=0, lastRead=4;
        while(res<n && lastRead==4){
            lastRead=read4(buf+res);
            res+=lastRead;
        }
        return min(res,n); 
    }
};