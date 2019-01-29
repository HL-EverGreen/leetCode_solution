class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 99.05%
        
        int idx = 0, size = paragraph.size(), max_cnt = 0;
        string temp, res;
        unordered_map<string, int> strCount;
        unordered_set<string> ban(banned.begin(), banned.end());
        paragraph += " ";
        for(auto ch : paragraph) {
            if(isalpha(ch)) temp += tolower(ch);
            else if(temp != "") { 
                if(ban.find(temp) == ban.end() && ++strCount[temp] > max_cnt) {
                    max_cnt = strCount[temp];
                    res = temp;
                }
                temp = "";
            }
        }
        return res;
        
        // more concise version
        /*
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(p);
        string w;
        pair<string, int> res ("", 0);
        while (iss >> w)
            if (ban.find(w) == ban.end() && ++count[w] > res.second)
                res = make_pair(w, count[w]);
        return res.first;
        */
    }
};