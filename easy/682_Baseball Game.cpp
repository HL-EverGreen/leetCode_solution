class Solution {
public:
    int calPoints(vector<string>& ops) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 100%
        
        vector<int> score;
        for(auto& ch : ops) {
           if(ch == "+") score.push_back(score[score.size() - 2] + score.back());
           else if(ch == "D") score.push_back(score.back() * 2);
           else if(ch == "C") score.pop_back();
           else score.push_back(atoi(ch.c_str()));
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};