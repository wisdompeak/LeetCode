class Solution {
    unordered_map<int,int>Father;
    int M;
    int N;
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) 
    {
        M=m;
        N=n;
        for (int i=0; i<m*n; i++)        
            Father[i]=-1;
        
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int count=0;
        vector<int>results;
        
        for (int i=0; i<positions.size(); i++)        
        {
            int x=positions[i].first;
            int y=positions[i].second;
            Father[x*N+y]=x*N+y;
            count++;
            
            for (int k=0; k<4; k++)
            {
                int a=x+dir[k].first;
                int b=y+dir[k].second;
                if (a<0||a>=M||b<0||b>=N) continue;
                if (Father[a*N+b]==-1) continue;
                if (FindSet(x*N+y)!=FindSet(a*N+b))
                {
                    Union(x*N+y,a*N+b);
                    count--;
                }                
            }
            results.push_back(count);
        }
        return results;
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
        bool flag;
        if (x/N<y<N)
            flag=1;
        else if (x/N==y<N && x%N<y%N)
            flag=1;
        else
            flag=0;
        
        if (flag)
            Father[y]=x;
        else
            Father[x]=y;
    }
};
