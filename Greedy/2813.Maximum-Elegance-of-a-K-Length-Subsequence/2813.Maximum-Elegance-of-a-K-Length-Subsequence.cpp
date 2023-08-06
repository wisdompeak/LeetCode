using LL = long long;
using PII = pair<LL,LL>;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) 
    {
        sort(items.rbegin(), items.rend());
        
        unordered_map<int,vector<int>>Map;
        LL sum = 0;
        for (int i=0; i<k; i++)
        {
            Map[items[i][1]].push_back(i);
            sum += items[i][0];            
        }
        
        LL t = (int)Map.size();                
        LL ret = sum + t*t;
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        for (int i=0; i<k; i++)        
            pq.push({items[i][0], items[i][1]});
        
        for (int i=k; i<items.size(); i++)
        {
            if (Map.find(items[i][1])!=Map.end()) continue;

            while (!pq.empty())
            {
                auto [val, cate] = pq.top();
                pq.pop();
                
                if (Map[cate].size()>1) 
                {                    
                    sum -= val;
                    sum += items[i][0];
                    t++;
                    Map[cate].pop_back();
                    Map[items[i][1]].push_back(i);
                    ret = max(ret, sum + t*t);                    
                    break;                    
                }
            }            
        }
        
        return ret;
        
    }
};
