/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        // array & DFS
        // 8ms, beats 100%
        
        int x = 0, y = 0, dir = 0;                              // initial at coord (x,y) with direction 0 (right)
        unordered_map<int, unordered_map<int, int>> visited;
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        clean(robot, visited, x, y, dir, dx, dy);
    }
    
    void clean(Robot& robot, unordered_map<int, unordered_map<int, int>>& visited, int x, int y, int dir, int* dx, int* dy) {
        if(visited[x][y] == 1) { return; }                      // if cleaned
        visited[x][y] = 1;
        robot.clean();
        
        for(int i = 0; i < 4; i++) {
            if(robot.move()) {
                x += dx[dir];
                y += dy[dir];
                clean(robot, visited, x, y, dir, dx, dy);
                robot.turnRight(); robot.turnRight();
                robot.move();
                robot.turnRight(); robot.turnRight();           // recover original status
                x -= dx[dir];
                y -= dy[dir];
            }
            robot.turnRight();
            dir = (dir + 1) % 4;
        }
    }
};