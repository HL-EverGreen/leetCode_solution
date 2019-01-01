class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // array & BFS
        // time complexity: ?, space complexity: ?
        // 472ms, beats 28.38%
        
        // $paths$ store current possible partial solutions
        // when solution is found, set min_lv
        // once the current solution's length > min_lv, break
        vector<vector<string>> res;
        queue<vector<string>> paths;
        unordered_set<string> word_list(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        int level = 1, min_lv = word_list.size() + 1;
        
        paths.push({beginWord});
        
        while(!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            
            // reach new level
            if(path.size() > level) {
                if(path.size() > min_lv) { break; }
                else { level = path.size(); }
                for(auto elem : visited) { word_list.erase(elem); }     // erase visited elements in word_list to avoid them being visited again
                visited.clear();
            }
            
            string last = path.back();
            for(int i = 0; i < last.size(); i++) {
                string news = last;
                for(char c = 'a'; c <= 'z'; c++) {
                    news[i] = c;
                    if(word_list.find(news) != word_list.end()) {
                        vector<string> new_path = path;                 // $path$ need to be reused in loop, so define new_path
                        new_path.push_back(news);
                        visited.insert(news);
                        if(news == endWord) {
                            min_lv = level;
                            res.push_back(new_path);
                        } else {
                            paths.push(new_path);
                        }
                    }
                }
            }
        }
        return res;
    }
};