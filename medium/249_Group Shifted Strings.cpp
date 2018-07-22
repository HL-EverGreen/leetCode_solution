class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> myMap;
        for(auto str:strings){
            myMap[getFeature(str)].push_back(str);
        }
        vector<vector<string>> res;
        vector<string> group;
        for(auto mp:myMap){
            group=mp.second;
            sort(group.begin(),group.end());
            res.push_back(group);
        }
        return res;
    }
    
    string getFeature(string& str){
        string t="";
        int diff=0;
        for(int i=1;i<str.length();i++){
            diff=str[i]-str[i-1];
            if(diff<0) diff+=26;
            t+='a'+diff+',';
        }
        return t;
    }
};