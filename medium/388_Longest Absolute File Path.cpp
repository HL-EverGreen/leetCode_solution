class Solution {
public:
    int lengthLongestPath(string input) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Use dirs to store length of different directories for current path.
        // Use '.' to determine whether encounter a file.
        // Only when encounter non '\n', '\t', calculate current max length
        
        input.push_back('\n');
        vector<int> dirs(256, 0);
        int res = 0;
        int N = input.size();
        for(int i = 0, level = 0, len = 0, is_file = 0; i < N; ++i) {
            switch(input[i]) {
                case '\n': level = len = is_file = 0; break;
                case '\t': ++level; break;
                case '.': is_file = 1;
                default:
                    dirs[level] = ++len;    // Update dir length for current path
                    if(is_file) res = max(res, level + accumulate(dirs.begin(), dirs.begin() + level + 1, 0));  // Add number of additional '/'
            }
        }
        return res;
    }
};