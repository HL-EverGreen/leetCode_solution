class Solution {
public:
    bool isIsomorphic(string s, string t) {//array
        int size_s=s.size(),size_t=t.size();
        if(size_s!=size_t) return false;
        int arr_s[128]={0},arr_t[128]={0};
        for(int i=0;i<size_s;i++){
            if(arr_s[s[i]]!=arr_t[t[i]]) return false;
            arr_s[s[i]]=arr_t[t[i]]=i+1;
        }
        return true;
    }
};