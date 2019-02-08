class Solution {
public:
    string minWindow(string s, string t) { //substring window
        // string & sliding window
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99%
        
        vector<int> dict(128, 0);
        for(auto ch : t) dict[ch]++;
        int start = 0, end = 0, head = 0, sSize = s.length(), min_dis = sSize + 1, remain = t.size();
        while(end < sSize) {
            if(dict[s[end++]]-- > 0) remain--;
            while(remain == 0) {
                if(min_dis > end - start) {
                    min_dis = end - start;
                    head = start;
                }
                if(dict[s[start++]]++ == 0) remain++;
            }
        }
        return min_dis > sSize ? "" : s.substr(head, min_dis);
    }
    
    //substring problem template
    /*
    vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { // initialize the hash map here // }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  // modify counter here // }

            while(// counter condition //){ 
                 
                 // update d here if finding minimum//

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ //modify counter here// }
            }  

            // update d here if finding maximum//
        }
        return d;
    */
};