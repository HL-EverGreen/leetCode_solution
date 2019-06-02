class Solution {
public:
    /* Hash key for unordered_set, or we can just use set */
    struct pairhash {
        public:
            template <typename T, typename U>
            std::size_t operator() (const std::pair<T, U> &x) const {
                return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
            }
    };
    
    int numSpecialEquivGroups(vector<string>& A) {
        // string & pattern
        // time complexity: O(mnlogn), m is the size of A, n is the largest length
        // space complexity: O(n)
        // 12ms, beats 92.13%
        
        // Main idea:
        // Simply use pair<string, string> to represent the pattern of a string
        // The first parameter is sorted odd charcter sets.
        // The second parameter is sorted even charcter sets.
        // And use set to remove pattern which belongs to the same group
        unordered_set<pair<string, string>, pairhash> res;
        
        for(auto s : A) {
            pair<string, string> p;
            int size = s.length();
            
            /* Create pair pattern for each string */
            for(int i = 0; i < size; i++) {
                if(i & 1) {
                    p.first += s[i];
                } else {
                    p.second += s[i];
                }
            }
            sort(p.first.begin(), p.first.end());
            sort(p.second.begin(), p.second.end());
            
            res.insert(p);
        }
        return res.size();
    }
};