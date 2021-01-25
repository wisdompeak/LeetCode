using PII = pair<int,int>;
class Solution {    
public:
    int eatenApples(vector<int>& apples, vector<int>& days) 
    {
        int count = 0;
        priority_queue<PII, vector<PII>, greater<PII>>pq;
        int i = 0;
        while (i<apples.size() || !pq.empty())
        {
            while (!pq.empty() && pq.top().first <= i)
                pq.pop();
            if (i<apples.size() && apples[i]>0)
                pq.push({i+days[i], apples[i]});
            if (!pq.empty())
            {
                auto x = pq.top();
                pq.pop();
                count++;
                if (x.second >= 2)
                    pq.push({x.first, x.second-1});
            }
            i++;
        }
        return count;
    }
};
