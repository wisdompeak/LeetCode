class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[2]<b[2];
    }
    unordered_map<int,int>Father;
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) 
    {
        for (int i=0; i<wells.size(); i++)
        {
            pipes.push_back({i+1,0,wells[i]});
        }
        
        sort(pipes.begin(),pipes.end(),cmp);
        
        for (int i=0; i<=wells.size(); i++)
            Father[i] = i;
        int ret  = 0;
        
        for (auto p:pipes)
        {
            int a = p[0];
            int b = p[1];
            if (FindSet(a)!=FindSet(b))
            {
                Union(a,b);
                ret+=p[2];
            }
        }
        
        return ret;
    }
    
    int FindSet(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindSet(Father[x]);
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
};
