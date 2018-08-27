class Solution {
public:
    bool isOneEditDistance(string s, string t) { //string
        int s_size=s.size(), t_size=t.size();
        if(s_size>t_size) return isOneEditDistance(t,s); //ensure that #t# is the longer(or equal long) string
        if(t_size-s_size>1) return false;
        bool mis_matched=false;
        for(int i=0;i<s_size;i++){
            if(s[i]!=t[i]){
                if(s_size==t_size) s[i]=t[i]; //if lengths are same, replace the mismatched element
                else s.insert(s.begin()+i,t[i]); //lengths are not same, insert mismatched element into rhe shorter string
                mis_matched=true;
                break;
            }
        }
        return (!mis_matched && t_size-s_size==1) || (mis_matched && s==t); //(!mis_matched && t_size-s_size==1) used to determine under the circumstance that mismatched element appears in the last element of #t# while t.size()==s.size()+1
    }
};