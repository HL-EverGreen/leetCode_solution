class Solution {
public:
    struct comp {
        bool operator() (const string& a, const string& b) {
            int i = a.find(' '), j = b.find(' ');
            return a.substr(i + 1) < b.substr(j + 1);
        }
    };
    
    // string & sort
    // time complexity: O(nlogn), space complexity: O(n)
    // 16ms, beats 97.89%
    
    // main idea:
    // Divided into two parts: letter-logs and digit-logs
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> num, alpha;
        for(auto& log : logs) {
            int i = log.find(' ');
            if(isdigit(log[i + 1])) num.push_back(log);
            else alpha.push_back(log);
        }
        sort(alpha.begin(), alpha.end(), comp());
        alpha.insert(alpha.end(), num.begin(), num.end());
        return alpha;
    }


    // method 2
    // stable_sort
    /*
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b) {
            int i = a.find(' '), j = b.find(' ');
            if(!isdigit(a[i + 1]) && !isdigit(b[j + 1])) return a.substr(i + 1) < b.substr(j + 1);
            return !isdigit(a[i + 1]);
        });
        return logs;
    }
    */
};