class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        // string
        // time complexity: O(nlogn), space complexity: O(n)
        // 4ms, beats 98.96%
        
        // replace from back to front, in-place modify
        vector<pair<int, int>> group;
        for(int i = 0; i < indexes.size(); i++) {
            group.push_back(make_pair(indexes[i], i));
        }
        sort(group.rbegin(), group.rend());
        for(auto g : group) {
            int i = g.first;
            string src = sources[g.second], target = targets[g.second];
            if(S.substr(i, src.length()) == src) {
                S = S.substr(0, i) + target + S.substr(i + src.length());
            }
        }
        return S;
    }
};