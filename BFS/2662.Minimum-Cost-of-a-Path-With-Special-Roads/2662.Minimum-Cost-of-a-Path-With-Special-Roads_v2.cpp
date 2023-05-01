using LL = long long;
using PLL = pair<LL, LL>;
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) 
    {
        map<LL, LL>dist;

        priority_queue<PLL, vector<PLL>, greater<>>pq;
        pq.push({0, encode(start[0], start[1])});
        for (auto& road: specialRoads)
        {            
            int x2 = road[2], y2 = road[3];                        
            LL pos2 = encode(x2,y2);
            pq.push({abs(start[0]-x2)+abs(start[1]-y2), pos2});
        }

        LL ret = INT_MAX;
        while (!pq.empty())
        {
            auto [len, pos] = pq.top();
            pq.pop();
            if (dist.find(pos)!=dist.end()) continue;
            dist[pos] = len;
            auto [x,y] = decode(pos);

            ret = min(ret, len+abs(x-target[0])+abs(y-target[1]));

            for (auto& road: specialRoads)
            {
                int x1 = road[0], y1 = road[1];
                int x2 = road[2], y2 = road[3];
                int cost = road[4];
                LL pos1 = encode(x1,y1);
                LL pos2 = encode(x2,y2);

                if (dist.find(pos2)==dist.end())
                    pq.push({len + abs(x-x1)+abs(y-y1) + cost, pos2});
            }
        }

        return ret;
    }

    LL encode(LL x, LL y) {return (x<<32) + y;}
    PLL decode(LL p) {return {p>>32, p%(1LL<<32)};}
};
