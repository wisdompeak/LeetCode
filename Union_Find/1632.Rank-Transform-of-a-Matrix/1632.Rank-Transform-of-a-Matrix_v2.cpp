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

        vector<pair<int,int>>nums;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                nums.push_back({matrix[i][j],{i*n+j}});

        for (int i=0; i<m; i++)
        {
            unordered_map<int,int>Map;
            for (int j=0; j<n; j++)
            {
                int val = matrix[i][j];
                if (Map.find(val)==Map.end())
                    Map[val] = i*n+j;
                else
                {
                    if (FindFather(Map[val])!=FindFather(i*n+j))
                        Union(Map[val], i*n+j);
                }                
            }
        }

        for (int j=0; j<n; j++)
        {
            unordered_map<int,int>Map;
            for (int i=0; i<m; i++)
            {
                int val = matrix[i][j];
                if (Map.find(val)==Map.end())
                    Map[val] = i*n+j;
                else
                {
                    if (FindFather(Map[val])!=FindFather(i*n+j))
                        Union(Map[val], i*n+j);
                }                
            }
        }

        unordered_map<int, vector<int>>Group;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                Group[FindFather(i*n+j)].push_back(i*n+j);
            }
                                        
        sort(nums.begin(), nums.end());
        vector<int>rowRank(m,0);
        vector<int>colRank(m,0);
        auto rets = vector<vector<int>>(m, vector<int>(n));

        for (auto p: nums)
        {
            int val = p.first;
            int x = p.second/n;
            int y = p.second%n;
            if (rets[x][y]!=0) continue; 
            
            int r = 0;            
            for (auto p: Group[Father[x*n+y]])
            {
                r = max(r, rowRank[p/n]);
                r = max(r, colRank[p%n]);
            }
            for (auto p: Group[Father[x*n+y]])
            {
                rowRank[p/n] = r+1;
                colRank[p%n] = r+1;
                rets[p/n][p%n] = r+1;
            }
        }
        return rets;
    }
};
