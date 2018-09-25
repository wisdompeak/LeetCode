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
    vector<pair<int,int>>nextDir = {{1,0},{0,1},{-1,0},{0,-1}};
    unordered_set<string>visited;
public:
    void cleanRoom(Robot& robot) 
    {
        DFS(robot,0,0,0);
    }
    
    void DFS(Robot& robot, int rows, int cols, int dir)
    {
        string room = to_string(rows)+"#"+to_string(cols);
        if (visited.find(room)!=visited.end())
            return;
        
        robot.clean();
        visited.insert(room);
        for (int k=0; k<4; k++)
        {
            int nextRow = rows+nextDir[(dir+k)%4].first;
            int nextCol = cols+nextDir[(dir+k)%4].second;
            if (robot.move())
            {
                DFS(robot, nextRow, nextCol, (dir+k)%4);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
};
