class Solution {
    vector<int>Father;
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        Father.resize(m*n);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                Father[i*n+j] = i*n+j;
                
        vector<vector<int>>next(m*n);        
        vector<int>inDegree(m*n,0);        
        
        for (int i=0; i<m; i++)
        {
            vector<pair<int,int>>temp;
            for (int j=0; j<n; j++)
                temp.push_back({matrix[i][j], i*n+j});
            sort(temp.begin(), temp.end());
            for (int j=1; j<n; j++)
            {
                if (temp[j].first>temp[j-1].first)
                {
                    next[temp[j-1].second].push_back(temp[j].second);
                    inDegree[temp[j].second]++;
                }                    
                else
                {
                    if (FindFather(temp[j-1].second)!=FindFather(temp[j].second))
                        Union(temp[j-1].second, temp[j].second);
                }                    
            }
        }
        
        for (int j=0; j<n; j++)
        {
            vector<pair<int,int>>temp;
            for (int i=0; i<m; i++)
                temp.push_back({matrix[i][j], i*n+j});
            sort(temp.begin(), temp.end());
            for (int i=1; i<m; i++)
            {
                if (temp[i].first>temp[i-1].first)
                {
                    next[temp[i-1].second].push_back(temp[i].second);
                    inDegree[temp[i].second]++;
                }                    
                else
                {
                    if (FindFather(temp[i-1].second)!=FindFather(temp[i].second))
                        Union(temp[i-1].second, temp[i].second);
                }                    
            }
        }
                        
        vector<vector<int>>group(m*n);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int root = FindFather(i*n+j);
                group[root].push_back(i*n+j);
                if (root!=i*n+j)
                    inDegree[root]+=inDegree[i*n+j];
            }
        
        queue<int>q;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (Father[i*n+j]==i*n+j && inDegree[i*n+j]==0)
                    q.push(i*n+j);
            }
        
        int idx = 1;
        auto rets = vector<vector<int>>(m,vector<int>(n,-1));
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();
                q.pop();
                
                for (auto connect: group[cur])
                    rets[connect/n][connect%n] = idx;
                                        
                for (auto connect: group[cur])
                    for (auto nxt: next[connect])
                    {
                        inDegree[Father[nxt]]--;
                        if (inDegree[Father[nxt]]==0)
                            q.push(Father[nxt]);
                    }                        
            }
            idx++;            
        }        
        return rets;        
    }
};
