class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // matrix & BFS
        // 16ms, beats 81.82%
        // main idea: convert matrix to string, and do BFS on each string for its all possible swap zero pairs
        
        // 双向BFS可以进一步减少时间复杂度, A*可以更小，启发式算法采用hamming distance（等长字符串不相同字符个数）
        
        // possible swap pairs
        unordered_map<int, vector<int>> moves({{0, {1, 3}}, {1, {0, 2, 4}}, {2, {1, 5}}, {3, {0, 4}}, {4, {1, 3, 5}}, {5, {2, 4}}});
        string s;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                s += to_string(board[i][j]);                    // initial string
        unordered_map<string, int> steps({{s, 0}});             // used to store string - sliding number pairs
        queue<pair<string, int>> status({{s, s.find('0')}});    // store string and its index of 0
        
        while(!status.empty() && status.front().first != "123450") {
            auto cur = status.front();
            for(auto dir : moves[cur.second]) {                 // find all possible moves
                string str = cur.first;
                swap(str[cur.second], str[dir]);
                if(steps.insert({str, steps[cur.first] + 1}).second)   // if steps does not contain that str (means that current step to this str is minimal)
                    status.push({str, dir});
            }
            status.pop();
        }
        return status.empty() ? -1 : steps["123450"];
    }
    
    // unordered_map.insert:
    // pair<iterator,bool> insert ( const value_type& val );
    // the function returns a pair object whose first element is an iterator pointing either to the newly inserted element in the container or to the element whose key is equivalent, and a bool value indicating whether the element was successfully inserted or not.
};