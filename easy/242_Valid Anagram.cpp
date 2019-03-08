class Solution {
public:
    bool isAnagram(string s, string t) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 12ms, beats 98.03%
        
        if(s.length() != t.length()) return false;
        vector<int> dict(26);
        for(auto& ch : s) dict[ch - 'a']++;
        for(auto& ch : t) if(--dict[ch - 'a'] < 0) return false;
        return true;

        // first step :)
        
        //actually, like alphabetic list we can simply use array instead of map,
        //to save the time consumption spent on every *find()* operation

        /*
        map<char,int> myMap;
        if(s.length()==0&&t.length()==0) return true;
        if(s.length()==0||t.length()==0) return false;
        if(s.length()!=t.length()) return false;
        
        for(int i=0;i<s.length();i++){
            if(myMap.find(s[i])!=myMap.end())
                myMap[s[i]]+=1;
            else myMap[s[i]]=1;
        }
        
        for(int i=0;i<t.length();i++){
            if(myMap.find(t[i])==myMap.end())
                return false;
            else myMap[t[i]]-=1;
        }
        
        map<char,int>::iterator iter;
        for(iter=myMap.begin();iter!=myMap.end();iter++){
            if(iter->second!=0)
                return false;
        }
        return true;
        */
    }
};