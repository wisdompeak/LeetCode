class Solution {
    unordered_map<int,int>Father;
    unordered_map<int,vector<int>>MapX;
    unordered_map<int,vector<int>>MapY;
    int N = 10000;
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        for (auto x:stones)
        {
            int i = x[0];
            int j = x[1];
            int id = i*N+j;
            Father[id] = id;
            MapX[i].push_back(id);
            MapY[j].push_back(id);
        }
        
        for (auto a: MapX)
        {
            int id0 = a.second[0];
            for (int i=1; i<a.second.size(); i++)
            {
                int id = a.second[i];
                if (FindFather(id0)!=FindFather(id))
                    Union(id0, id);                
            }
        }
        
        for (auto a: MapY)
        {
            int id0 = a.second[0];
            for (int i=1; i<a.second.size(); i++)
            {
                int id = a.second[i];
                if (FindFather(id0)!=FindFather(id))
                    Union(id0, id);                
            }
        }
        
        unordered_set<int>Set;
        for (auto x: stones)
        {
            int id = x[0]*N+x[1];
            int id0 = FindFather(id);
            Set.insert(id0);
        }
        
        return stones.size() - Set.size();
    }
    
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
        if (x<=y)
            Father[y] = x;
        else
            Father[x] = y;
     }
};
