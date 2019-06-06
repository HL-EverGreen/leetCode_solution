class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // BFS, also can use DFS
        // 4ms, beats 99.89%
        
        // Main idea:
        // Use unordered_set to record visited room, and stack to store keys to open new room
        unordered_set<int> visited_room = {0};
        queue<int> keys;
        keys.push(0);
        
        while(!keys.empty()) {
            int key = keys.front();
            keys.pop();
            for(auto nk : rooms[key]) {
                if(visited_room.count(nk) == 0) {
                    visited_room.insert(nk);
                    keys.push(nk);
                }
            }
        }
        return visited_room.size() == rooms.size();
    }
};