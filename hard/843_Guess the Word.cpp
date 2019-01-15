/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        // array
        // 0ms, beats 100%
        
        // Use score to label each word's value, select the word with highest score to be candidate (the one can maximum information gathered by guess)
        // After each guess, erase word list by gudging whether match(*it, candidate) == res, if not, erase the word
    
        vector<vector<int>> probs(6, vector<int>(26, 0));
        list<string> rem_words;
        int res = 0;
        
        for(auto w : wordlist) {
            rem_words.push_back(w);
            for(int i = 0; i < 6; i++) {
                probs[i][w[i] - 'a']++;
            }
        }
        
        while(res < 6) {
            string candidate = bestCandidate(rem_words, probs);
            res = master.guess(candidate);
            for(auto it = rem_words.begin(); it != rem_words.end();) {
                if(match(*it, candidate) != res) {
                    for(int i = 0; i < 6; i++) {
                        probs[i][(*it)[i] - 'a']--;
                    }
                    it = rem_words.erase(it);
                } else { it++; }
            }
        }
    }
    
    int match(string s1, string s2) {
        int res = 0;
        for(int i = 0; i < s1.size(); i++) if(s1[i] == s2[i]) { res++; }
        return res;
    }
    
    string bestCandidate(list<string>& words, vector<vector<int>>& probs) {
        int max_score = 0;
        string best;
        for(auto w : words) {
            int score = 1;
            for(int i = 0; i < 6; i++) { score *= probs[i][w[i] - 'a']; }
            if(score > max_score) {
                max_score = score;
                best = w;
            }
        }
        return best;
    }
};