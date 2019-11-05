class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // method 1
        // BFS
        // 1380ms, beats 18.26%
        
        // main idea:
        // Use unordered_set to store unused word
        // Push all possible word which is also in dict into queue

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                dict.erase(cur);                                        // delete word in unused set
                if(cur == endWord) return step;
                for(int j = 0; j < cur.length(); j++) {                 // try all possibilities
                    char tmp = cur[j];
                    for(int k = 0; k < 26; k++) {
                        cur[j] = 'a' + k;
                        if(dict.find(cur) != dict.end()) q.push(cur);
                    }
                    cur[j] = tmp;
                }
            }
            step++;
        }
        return 0;
        
        
        // method 2
        // Bi-BFS
        // 28ms, beats 98.34%
        
        // main idea:
        // Start BFS from begin word and end word simultaneously
        
        unordered_set<string> remain(wordList.begin(), wordList.end());
        if(!remain.count(endWord)) return 0;
        remain.erase(endWord);
        
        unordered_set<string> p1, p2;
        p1.insert(beginWord); p2.insert(endWord);
        int step = 2;
        
        while(!p1.empty() && !p2.empty()) {
            if(p1.size() > p2.size()) swap(p1, p2);     // Expand search in the one with smaller size, to optimize the time complexity
            unordered_set<string> next;
            for(auto it = p1.begin(); it != p1.end(); ++it){
                string cur = *it;
                for(int i = 0; i < cur.length(); ++i) {
                    char tmp = cur[i];
                    for(int j = 0; j < 26; ++j) {
                        cur[i] = 'a' + j;
                        if(p2.count(cur)) return step;
                        if(remain.count(cur)) {
                            next.insert(cur);
                            remain.erase(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
            swap(p1, next); // Replace current search set with new one
            ++step;
        }
        return 0;
    }
};