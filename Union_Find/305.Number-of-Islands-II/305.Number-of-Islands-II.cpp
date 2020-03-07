class Solution {
    vector<int>Father;
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) 
    {
        Father.resize(m*n);
        for (int i=0; i<m*n; i++)         
             Father[i]=-1;
        
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int count=0;
        vector<int>result;
        
        for (int i=0; i<positions.size(); i++)
        {
            int x=positions[i][0];
            int y=positions[i][1];
            if (Father[x*n+y]!=-1)
            {
                result.push_back(result.back());
                continue;
            }
            
            Father[x*n+y]=x*n+y;
            count+=1;
            
            for (int k=0; k<4; k++)
            {
                int a=x+dir[k].first;
                int b=y+dir[k].second;
                if (a<0||a>=m||b<0||b>=n)
                    continue;
                if (Father[a*n+b]==-1)
                    continue;
                if (FindSet(a*n+b)!=FindSet(x*n+y))
                {
                    count--;
                    Union(a*n+b,x*n+y);                    
                }                    
            }
            result.push_back(count);
        }
        
        return result;
    }
    
    int FindSet(int x)
    {
        if (x!=Father[x])
            Father[x]=FindSet(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x=Father[x];
        y=Father[y];
        
        if (x<y)
            Father[y]=x;
        else
            Father[x]=y;        
    }
};
