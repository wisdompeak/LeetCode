class Solution {
public:
    int dis(vector<vector<int>>& workers, vector<vector<int>>& bikes, int i, int j)
    {
        int x1=workers[i][0];
        int y1=workers[i][1];
        int x2=bikes[j][0];
        int y2=bikes[j][1];
        return abs(x1-x2)+abs(y1-y2);
    }
    
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        set<vector<int>>Set;
        Set.insert({0,0,0});
        
        set<vector<int>>visited;
        
        while (true)
        {
            int cost = (*Set.begin())[0];
            int i = (*Set.begin())[1];
            int taken = (*Set.begin())[2];
            Set.erase(Set.begin());
            
            if (i==workers.size())
                return cost;
            
            if (visited.find({i,taken})!=visited.end())
                continue;
            visited.insert({i,taken});
            
            for (int j=0; j<bikes.size(); j++)
            {
                if ((taken&(1<<j)) !=0)
                    continue;
                Set.insert({cost+dis(workers, bikes, i,j), i+1, taken+(1<<j)});
            }            
        }
        
        return 0;
    }
};
