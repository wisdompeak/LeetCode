class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        unordered_map<int,int>Map;
        for (auto x:barcodes)
            Map[x]+=1;
        priority_queue<pair<int,int>>pq;
        for (auto x: Map)
            pq.push({x.second, x.first});

        vector<int>ret;
        while (!pq.empty())
        {
            if (pq.size()<2 && pq.top().first>1)
                return {};
                        
            vector<pair<int,int>>temp;
            int len = pq.size();
            for (int i=0; i<min(2, len); i++)
            {
                ret.push_back(pq.top().second);                
                if (pq.top().first!=1)
                    temp.push_back(pq.top());
                pq.pop();
            }

            for (auto x: temp)
            {
                x.first -= 1;
                pq.push(x);
            }
                
        }

        return ret;
    }
};
