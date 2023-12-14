class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) 
    {
        int ret = 0;
        for (int state=0; state<(1<<n); state++)
        {
            vector<vector<int>>d(n, vector<int>(n, INT_MAX/3));
            for (int i=0; i<n; i++)
            {
                if (((state>>i)&1)==0) continue;
                d[i][i] = 0;
            }
                
            for (auto road: roads)
            {
                int a = road[0], b = road[1], w = road[2];
                if (((state>>a)&1)==0) continue;
                if (((state>>b)&1)==0) continue;
                
                for (int i=0; i<n; i++)
                {
                    if (((state>>i)&1)==0) continue;
                    for (int j=0; j<n; j++)
                    {
                        if (((state>>j)&1)==0) continue;
                        d[i][j] = min(d[i][j], d[i][a]+w+d[b][j]);
                        d[i][j] = min(d[i][j], d[i][b]+w+d[a][j]);
                    }
                }                    
            }            
            
            int flag = 1;            
            for (int i=0; i<n; i++)
            {
                if (((state>>i)&1)==0) continue;
                for (int j=0; j<n; j++)
                {
                    if (((state>>j)&1)==0) continue;
                    if (d[i][j]>maxDistance)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag==0) break;
            }
            if (flag)  ret++;
        }
        
        return ret;        
    }
};
