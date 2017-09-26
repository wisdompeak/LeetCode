
class Solution {
    vector<int>Father;
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int N=M.size();
        
        for (int i=0; i<N; i++)
            Father.push_back(i);
        
        for (int i=0; i<N; i++)
         for (int j=0; j<N; j++)
         {
             if (M[i][j]==0) continue;
             
             if (FindSet(i)!=FindSet(j))
                 Union(i,j);             
         }
        
        unordered_set<int>Set;
        for (int i=0; i<N; i++)
        {
            Father[i] = FindSet(i);
            Set.insert(Father[i]);
        }
            
        return Set.size();
    }
    
    int FindSet(int x)
    {
        if (x!=Father[x])
        {
            Father[x]=FindSet(Father[x]);
        }
        return Father[x];
    }
    
    void Union (int x, int y)
    {
        x=Father[x];
        y=Father[y];
        if (x<=y)
            Father[y]=x;
        else
            Father[x]=y;
    }
};
