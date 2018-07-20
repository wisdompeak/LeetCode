class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        if (startFuel>=target) return 0;
        
        stations.push_back({target,0});
        
        int stationID = 0;
        int curFuel = startFuel;
        priority_queue<int>pq;
        int count = 0;
        
        while (stationID<stations.size())
        {
            if (curFuel>=stations[stationID][0])
            {
                pq.push(stations[stationID][1]);
                stationID++;                
            }
            else
            {
                while (curFuel<stations[stationID][0] && pq.size()>0)
                {
                    curFuel+=pq.top();
                    pq.pop();
                    count+=1;
                }
                
                if (curFuel<stations[stationID][0] && pq.size()==0)
                    return -1;
            }
        }
        
        return count;        
    }
};
