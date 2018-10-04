class Solution {
    int color[50][50][3];
    
public:
    int catMouseGame(vector<vector<int>>& graph) 
    {
        int N = graph.size();
                
        queue<vector<int>>q;
        for (int i=0; i<N; i++)
            for (int turn=1; turn<=2; turn++)
            {
                color[0][i][turn] = 1;  // mouse win conditions
                q.push({0,i,turn});
                
                if (i!=0)               
                {
                    color[i][i][turn] = 2;  // cat win conditions
                    q.push({i,i,turn});
                }
            }
        
        while (!q.empty())
        {            
            int m = q.front()[0]; 
            int c = q.front()[1];
            int t = q.front()[2];            
            int status = color[m][c][t];
            q.pop();
                        
            for (auto nextNode: findAllParents(graph,m,c,t))
            {
                int m2 = nextNode[0];
                int c2 = nextNode[1];
                int t2 = nextNode[2];
                
                if (color[m2][c2][t2]!=0) continue; // has been determined
                
                if (t2==status)   // immediate win, (m2,c2,t2)->(m,c,t)
                {
                    color[m2][c2][t2] = status;
                    q.push({m2,c2,t2});                    
                }
                else if (allChildrenWin(graph, m2,c2,t2))    // eventually lose
                {
                    color[m2][c2][t2] = (t2==1)? 2:1;
                    q.push({m2,c2,t2});                
                }                
            }
        }
        return color[1][2][1];
    }
    
    
    vector<vector<int>> findAllParents(vector<vector<int>>& graph, int m, int c, int t)
    {
        vector<vector<int>>neighbours;
        if (t==1)
        {
            for (int c_next: graph[c])
                if (c_next!=0) neighbours.push_back({m,c_next,2});
        }
        else
        {
            for (int m_next: graph[m])
                neighbours.push_back({m_next,c,1});
        }
        return neighbours;
    }
    
    bool allChildrenWin(vector<vector<int>>& graph, int m, int c, int t)
    {
        if (t==1)
        {
            for (int m_next: graph[m])
                if (color[m_next][c][2]!=2)
                    return false;
        }
        else if (t==2)
        {
            for (int c_next: graph[c])
                if (c_next!=0 && color[m][c_next][1]!=1)
                    return false;
        }
        return true;
    }
};
