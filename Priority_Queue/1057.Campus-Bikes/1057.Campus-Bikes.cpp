class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        int m = workers.size();
        int n = bikes.size();
        vector<queue<array<int,3>>>d(m);
        for (int i=0; i<m; i++)
        {
            vector<array<int,3>>temp(n);
            for (int j=0; j<n; j++)
            {
                int x = abs(workers[i][0]-bikes[j][0]);
                int y = abs(workers[i][1]-bikes[j][1]);
                temp[j] = {x+y,i,j};
            }
            sort(temp.begin(), temp.end());          
            for (auto x: temp)
                d[i].push(x);
        }
                    
        set<array<int,3>>Set;
        for (int i=0; i<m; i++)
        {            
            Set.insert(d[i].front());
        }        
        
        vector<int>rets(m, -1);        
        vector<int>bikesDone(n,0);
        for (int i=0; i<m; i++)
        {            
            int w = (*Set.begin())[1];
            int b = (*Set.begin())[2];
            rets[w] = b;            
            bikesDone[b] = 1;
            
            Set.clear();
            for (int i=0; i<m; i++)
            {
                if (rets[i]!=-1) continue;
                while (!d[i].empty() && bikesDone[d[i].front()[2]])
                    d[i].pop();
                if (!d[i].empty())
                    Set.insert(d[i].front());
            }            
        }
        
        return rets;  
    }
};
