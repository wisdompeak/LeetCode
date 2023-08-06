using LL = long long;
using PII = pair<LL, LL>;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) 
    {
        sort(items.rbegin(), items.rend());

        LL sum = 0;
        unordered_map<int, int>Map;
        for (int i=0; i<k; i++)
        {
            sum += items[i][0];
            Map[items[i][1]]++;
        }

        LL t = Map.size();
        LL ret = sum + t*t;

        priority_queue<PII, vector<PII>, greater<>>pq;
        for (int i=0; i<k; i++)
            pq.push({items[i][0], items[i][1]});

        for (int i=k; i<items.size(); i++)
        {
            if (Map.find(items[i][1])!=Map.end()) continue;

            while (!pq.empty())
            {
                auto [profit, cate] = pq.top();
                pq.pop();

                if (Map[cate] > 1)
                {
                    sum -= profit;
                    sum += items[i][0];
                    t++;
                    Map[cate]--;
                    Map[items[i][1]]++;

                    ret = max(ret, sum + t*t);
                    break;
                }
            }
        }

        return ret;
    }
};
