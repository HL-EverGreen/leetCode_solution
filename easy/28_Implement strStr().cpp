class Solution {
public:
    int strStr(string haystack, string needle) { //string
        int hay_size=haystack.size(), nd_size=needle.size(), start=0;
        while(true){
            if(nd_size+start>hay_size) return -1;
            if(haystack.substr(start,nd_size)==needle) return start;
            while(start++<hay_size-nd_size && haystack[start]!=needle[0]);
        }
    }
};