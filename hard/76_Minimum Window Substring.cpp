class Solution {
public:
    string minWindow(string s, string t) { //substring window
        vector<int> map(128,0);
        for(auto c:t) map[c]++;
        int counter=t.size(), begin=0, end=0, min_dis=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--;
            while(counter==0){ //valid subset
                if(end-begin<min_dis){
                    min_dis=end-begin;
                    head=begin;
                }
                if(map[s[begin++]]++==0) counter++;  //make invalid
            }
        }
        return min_dis>s.size()?"":s.substr(head,min_dis);
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