class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int,char>>pq;
        if (a!=0) pq.push({a,'a'});
        if (b!=0) pq.push({b,'b'});
        if (c!=0) pq.push({c,'c'});

        string ret;
        while (!pq.empty())
        {
            if (pq.size()==1) 
            {
                int k = min(2, pq.top().first);
                for (int i=0; i<k; i++)                    
                    ret.push_back(pq.top().second);
                return ret;
            }

            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();

            int k = min(1+x.first-y.first, 2);
            for (int i=0; i<k; i++)
                ret.push_back(x.second);
            ret.push_back(y.second);

            x.first-=k;
            y.first-=1;
            if (x.first!=0) pq.push(x);
            if (y.first!=0) pq.push(y);

            // cout<<ret<<endl;
        }
        return ret;
        
    }
};
