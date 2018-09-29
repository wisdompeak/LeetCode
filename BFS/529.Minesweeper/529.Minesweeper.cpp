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
        
        auto dir = vector<pair<int,int>>({{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}});
        set<pair<int,int>>visited;
        
        queue<pair<int,int>>q;
        q.push({click[0],click[1]});
        visited.insert({click[0],click[1]});
        
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            vector<pair<int,int>>next;
            int count = 0;
            for (int k=0; k<8; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=M||y<0||y>=N) continue;
                if (board[x][y]!='E' && board[x][y]!='M') continue;
                                
                if (board[x][y]=='M') count++;
                else if (visited.find({x,y})==visited.end())
                    next.push_back({x,y});
            }
            
            if (count>0)            
                board[i][j]=count+'0';                            
            else
            {
                board[i][j]='B';
                for (auto p:next)
                {
                    q.push(p);
                    visited.insert(p);
                }                    
            }
        }
        
        return board;
    }
};
