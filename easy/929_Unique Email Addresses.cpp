class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 28ms, beats 96.43%
        
        unordered_set<string> unique = {};
        for(const auto& email : emails)
        {
            int pivot = email.find_first_of('@'); 
            string name = email.substr(0, pivot), domain = email.substr(pivot);
            name.erase(remove_if(name.begin(), name.end(), [](const auto& c){ return c == '.'; }), name.end());
            unique.insert(name.erase(name.find_first_of('+')) + domain);
        }
        return static_cast<int>(unique.size());


        // erase
        // 1: string& erase (size_t pos = 0, size_t len = npos);
        // 2: iterator erase (iterator p);
        // 3: iterator erase (iterator first, iterator last);

        // remove_if
        // 和remove一样不会修改容器大小，故需要配合erase把后面不需要的部分删去
    }
};