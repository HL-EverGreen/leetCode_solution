struct hash_pair {
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        // Design & deque
        // time complexity: Move(): O(1), space complexity: O(n)
        // 180ms, beats 86.4%
        
        // Main idea:
        // Use deque to mock the snake's node from tail to head.
        // And use hashset to record its occupied blocks.
        
        this->food = food;
        coverd.insert({0, 0});
        snake.push_back({0, 0});
        this->height = height; this->width = width;
        idx = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = snake.back().first, col = snake.back().second;
        pii tail = snake.front(); snake.pop_front();                // Remove tail
        coverd.erase(tail);
        
        // Update head
        if(direction == "U") --row;
        else if(direction == "L") --col;
        else if(direction == "R") ++col;
        else if(direction == "D") ++row;
        else return -1;
        
        // Check new head
        if(row < 0 || col < 0 || row >= height || col >= width || coverd.count({row, col})) return -1;
        
        // Add new head
        snake.push_back({row, col});
        coverd.insert({row, col});
        
        // Eat all fruits
        if(idx >= food.size()) return coverd.size() - 1;
        
        // Eat fruit, add tail back to snake
        if(row == food[idx][0] && col == food[idx][1]) {
            snake.push_front(tail);
            coverd.insert(tail);
            ++idx;
        }
        return coverd.size() - 1;
    }
    
private:
    typedef pair<int, int> pii;
    deque<pii> snake;
    unordered_set<pii, hash_pair> coverd;
    vector<vector<int>> food;
    int height, width, idx;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

