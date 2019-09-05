class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int M = board.size();
        int N = board[0].size();
        
        if (board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        auto visited = vector<vector<int>>(M,vector<int>(N,0));
        auto dir = vector<pair<int,int>>({{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}});
        
        queue<pair<int,int>>q;
        q.push({click[0],click[1]});
        visited[click[0]][click[1]] = 1;
        
        while (!q.empty())
        {
            int x0 = q.front().first;
            int y0 = q.front().second;
            q.pop();
            
            int count = 0;
            vector<pair<int,int>>next;
            
            for (int k=0; k<8; k++)
            {
                int x = x0+dir[k].first;
                int y = y0+dir[k].second;
                
                if (x<0||x>=M||y<0||y>=N)
                    continue;
                
                if (board[x][y]=='M')
                    count++;
                else
                {
                    if (visited[x][y]==0)
                        next.push_back({x,y});
                }
                    
            }
            
            if (count==0)
            {
                board[x0][y0] = 'B';
                for (auto p: next)
                {
                    q.push(p);
                    visited[p.first][p.second] = 1;
                }  
            }
            else
            {
                board[x0][y0] = '0'+count;
            }
        }
        
        return board;
    }
};
