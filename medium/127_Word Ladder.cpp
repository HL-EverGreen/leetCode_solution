class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // method 1
        // BFS
        // 1380ms, beats 18.26%
        
        // main idea:
        // Use unordered_set to store unused word
        // Push all possible word which is also in dict into queue
        /*
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
        */
        
        // method 2
        // Bi-BFS
        // 32ms, beats 97.52%
        
        // main idea:
        // Start BFS from begin word and end word simultaneously
        
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end()) return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {                                    // always expand from the one has less word candidate (in order to decrease space used)
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead -> begin(); it != phead -> end(); it++) {    
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail -> find(word) != ptail -> end()) {            // find word ladder
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead -> swap(temp);                                                // set corresponding set (head or tail) to next search set
        }
        return 0;
    }
};