using LL = long long;
using PLL = pair<LL, LL>;
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) 
    {
        priority_queue<PLL, vector<PLL>, greater<>>pq;   // {dist to node, node id}
        pq.push({0, encode(start[0], start[1])});
        for (auto& road: specialRoads)
        {
            int x = road[2], y = road[3];
            pq.push({abs(start[0]-x)+abs(start[1]-y), encode(x,y)});
        }

        map<LL, LL>dist;
        LL ret = INT_MAX;
        while (!pq.empty())
        {
            auto [len, id] = pq.top();
            pq.pop();
            if (dist.find(id)!=dist.end()) continue;
            dist[id] = len;
            auto [x,y] = decode(id);

            ret = min(ret, len + abs(x-target[0])+abs(y-target[1]));

            for (auto& road: specialRoads)
            {
                int x1 = road[0], y1 = road[1];
                int x2 = road[2], y2 = road[3];
                int cost = road[4];
                LL id2 = encode(x2,y2);

                if (dist.find(id2)==dist.end())                
                    pq.push({len + abs(x-x1)+abs(y-y1) + cost, id2});
            }

        }

        return ret;
    }

    LL encode(LL x, LL y) {return (x<<32) + y;}
    PLL decode(LL id) {return {id>>32, id%(1LL<<32)};}
};
