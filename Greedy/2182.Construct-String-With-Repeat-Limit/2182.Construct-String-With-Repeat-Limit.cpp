class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        unordered_map<char,int>Map;
        for (auto ch: s)
            Map[ch]++;
        
        priority_queue<pair<char,int>>pq;
        
        for (auto x:Map)
            pq.push(x);
        
        string ret;
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            
            if (x.second <= repeatLimit)
            {
                for (int i=0; i<x.second; i++)
                    ret.push_back(x.first);
                continue;
            }
            
            int k = min(x.second, repeatLimit);
            for (int i=0; i<k; i++)
                ret.push_back(x.first);            
            x.second -= k;
                        
            if (pq.empty()) return ret;
            
            auto y = pq.top();
            pq.pop();
            ret.push_back(y.first);
            y.second -= 1;
            
            if (x.second!=0)
                pq.push(x);
            if (y.second!=0)
                pq.push(y);
        }
        
        return ret;        
    }
};
