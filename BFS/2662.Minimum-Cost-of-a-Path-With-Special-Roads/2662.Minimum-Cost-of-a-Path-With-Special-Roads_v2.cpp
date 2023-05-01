using LL = long long;
using PLL = pair<LL, LL>;
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) 
    {
        map<LL, LL>dist;

        specialRoads.push_back({start[0], start[1], target[0], target[1], abs(start[0]-target[0])+abs(start[1]-target[1])});

        priority_queue<PLL, vector<PLL>, greater<>>pq;
        pq.push({0, encode(start[0], start[1])});

        while (!pq.empty())
        {
            auto [len, pos] = pq.top();
            pq.pop();
            if (dist.find(pos)!=dist.end()) continue;
            dist[pos] = len;
            auto [x,y] = decode(pos);

            if (x==target[0] && y==target[1]) return len;

            for (auto& road: specialRoads)
            {
                int x1 = road[0], y1 = road[1];
                int x2 = road[2], y2 = road[3];
                int cost = road[4];
                LL pos1 = encode(x1,y1);
                LL pos2 = encode(x2,y2);
              
                if (dist.find(pos2)==dist.end())
                {
                    int d1 = abs(x-x1)+abs(y-y1) + cost;
                    int d2 = abs(x-x2)+abs(y-y2);
                    pq.push({len+min(d1,d2), pos2});
                }
            }
        }

        return -1;
    }

    LL encode(LL x, LL y) {return (x<<32) + y;}
    PLL decode(LL p) {return {p>>32, p%(1LL<<32)};}
};
