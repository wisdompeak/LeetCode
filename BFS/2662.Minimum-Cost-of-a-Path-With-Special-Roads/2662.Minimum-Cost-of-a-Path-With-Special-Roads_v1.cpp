using LL = long long;
class Solution {
    int dp[405][405];
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) 
    {
        specialRoads.push_back({start[0], start[1], target[0], target[1], abs(start[0]-target[0])+abs(start[1]-target[1])});

        vector<pair<int,int>>point;
        map<LL, LL>reverseMap;
        for (int i=0; i<specialRoads.size(); i++)
        {
            auto& road = specialRoads[i];
            int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], c = road[4];                        
            LL point1 = encode(x1,y1), point2 = encode(x2,y2);
            if (reverseMap.find(point1)==reverseMap.end())
            {
                point.push_back({x1,y1});
                reverseMap[point1] = point.size()-1;
            }
            if (reverseMap.find(point2)==reverseMap.end())
            {
                point.push_back({x2,y2});
                reverseMap[point2] = point.size()-1;
            }
        }
        int n = point.size();
        
        for (int i=0; i<n; i++)            
            dp[i][i] = 0;
        
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {                          
                auto [x1,y1] = point[i];
                auto [x2,y2] = point[j];
                dp[i][j] = dp[j][i] = abs(x1-x2)+abs(y1-y2);
            }
        
        for (auto& road: specialRoads)
        {            
            int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], c = road[4];            
            int i = reverseMap[encode(x1,y1)], j = reverseMap[encode(x2,y2)];
            dp[i][j] = min(dp[i][j], c);
        }
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);

        int i = reverseMap[encode(start[0],start[1])], j = reverseMap[encode(target[0],target[1])];    
        return dp[i][j];
    }

    LL encode(LL x, LL y) {return (x<<32) + y;}
};
