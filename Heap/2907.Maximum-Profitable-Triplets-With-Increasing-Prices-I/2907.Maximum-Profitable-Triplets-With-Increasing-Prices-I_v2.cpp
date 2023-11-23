class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) 
    {
        int n = prices.size();
        map<int,int>Map;
        
        vector<int>left(n, -1);
        for (int i=0; i<n; i++)
        {                        
            auto iter = Map.lower_bound(prices[i]);
            if (iter!=Map.begin())
            {                
                left[i] = prev(iter)->second;
            }
            if (Map.find(prices[i])!=Map.end() && profits[i]<=Map[prices[i]])
                continue;                        
            if (profits[i] <= left[i])
                continue;
            Map[prices[i]] = profits[i];
            
            iter = Map.upper_bound(prices[i]);
            while (iter!=Map.end() && iter->second <= profits[i])
                iter = Map.erase(iter);
        }

        Map.clear();
        vector<int>right(n, -1);
        for (int i=n-1; i>=0; i--)
        {
            auto iter = Map.upper_bound(prices[i]);
            if (iter!=Map.end())
            {                
                right[i] = iter->second;
            }
            if (Map.find(prices[i])!=Map.end() && profits[i]<=Map[prices[i]])
                continue;
            if (profits[i] <= right[i])
                continue;
            Map[prices[i]] = profits[i];   

            iter = Map.find(prices[i]);            
            map<int,int>::reverse_iterator rit(iter);
            // Note rit is actually at a one-position diff before iter.       
            vector<int>to_delete;
            while (rit!=Map.rend() && rit->second <= profits[i])
            {                
                int key = rit->first;
                rit = next(rit);
                to_delete.push_back(key);  
            }
            for (auto key: to_delete) Map.erase(key);
        }
      
        int ret = -1;
        for (int i=0; i<n; i++)
        {
            if (left[i]!=-1 && right[i]!=-1)
                ret = max(ret, left[i]+right[i]+profits[i]);
        }
        return ret;
    }
};
