class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // string & hash table
        // time complexity: O(n^2logn), space complexity: O(n)
        // 28ms, beats 96.42%
        
        // actually we can use special sort instead of sort (which takes nlogn time), code is listed below
        unordered_map<string, vector<string>> group;
        vector<vector<string>> res;
        for(auto s: strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            group[s].push_back(tmp);
        }
        
        for(auto g : group) {
            res.push_back(g.second);
        }
        
        return res;
    }
    
    // special sort function, takes O(n) time
    /*
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
    */
};