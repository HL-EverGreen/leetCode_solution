class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {//sort_string_and_unordered_map
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        //int i=0;
        for(auto s:strs){
            string tmp=s;
            sort(s.begin(),s.end());
            mp[s].push_back(tmp); //use tmp=s instead strs[i] to save running time
        }
        for(auto m:mp){
            res.push_back(m.second);
        }
        return res;
    }
};