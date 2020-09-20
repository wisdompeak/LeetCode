class Solution {
    int numNodes;    
    vector<vector<int>>next;
    
bool bfs() 
{        
    queue<int>q;
    int count = 0;

    vector<int>InDegree(numNodes,0);
    for (int i=0; i<numNodes; i++)
    	for (int j: next[i])
    		InDegree[j]++;

    for (int i=0; i<numNodes; i++)
    {
        if (InDegree[i]==0) 
        {
            q.push(i);
            count++;
        }
    }
                
    while (!q.empty())
    {
        int curCourse = q.front();
        q.pop();
        for (auto child: next[curCourse])
        {
            InDegree[child]--;
            if (InDegree[child]==0)
            {
                q.push(child);
                count++;
            }                    
        }
    }        
    
    return count==numNodes;        
}    
    
public:
    bool isPrintable(vector<vector<int>>& targetGrid) 
    {
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        vector<int>left(61, n);
        vector<int>right(61, -1);
        vector<int>top(61, m);
        vector<int>bottom(61, -1);
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int color = targetGrid[i][j];
                left[color] = min(left[color], j);
                right[color] = max(right[color], j);
                top[color] = min(top[color], i);
                bottom[color] = max(bottom[color], i);
            }
        
        next.resize(61);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                for (int color=1; color<=60; color++)
                {
                    if (i>=top[color]&&i<=bottom[color]&&j>=left[color]&&j<=right[color])
                    {
                        if (color!=targetGrid[i][j])
                            next[targetGrid[i][j]].push_back(color);
                    }
                }                
            }

        numNodes = 61;       
        return bfs();
    }
};
