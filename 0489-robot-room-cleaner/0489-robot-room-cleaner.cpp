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
    unordered_set<string> visited;
    void cleanRoom(Robot& robot) {
        string code = to_string(0)+ '#' + to_string(0);
        visited.insert(code);
        dfs(robot, 0, 0, 0);
    }

    void dfs(Robot& robot, int x, int y, int d) {
        robot.clean();
        vector<pair<int, int>> dir{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        for(int k = 1; k <= 4; ++k) {
            int nd = (d + k) % 4;
            int tx = x + dir[nd].first;
            int ty = y + dir[nd].second;
            robot.turnRight();
            string code = to_string(tx) + '#' + to_string(ty);
            if(visited.find(code) == visited.end() and robot.move()) {
                visited.insert(code);
                dfs(robot, tx, ty, nd);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
        }
    }
};