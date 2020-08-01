class Solution {
public:
    string strWithout3a3b(int A, int B) 
    {
        priority_queue<pair<int,char>>pq;
        pq.push({A,'a'});
        pq.push({B,'b'});

        string ret;
        while (!pq.empty())
        {
            if (pq.size()==1) 
            {
                int k = pq.top().first;
                if (k>2)
                    return "";
                else
                {
                    for (int i=0; i<k; i++)                    
                        ret.push_back(pq.top().second);
                    return ret;
                }
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
        }
        return ret;
    }

};
