using PII = pair<int,int>;
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) 
    {
        int m = values.size();
        int n = values[0].size();

        priority_queue<PII, vector<PII>, greater<>>pq;
        vector<int>p(m, n-1);
        for (int i=0; i<m; i++)
            pq.push({values[i].back(), i});

        long long ret = 0;
        int d = 1;
        for (int t=0; t<m*n; t++)
        {            
            auto [v,i] = pq.top();
            pq.pop();
            ret += (long long)v * d;
            if (p[i]!=0)
            {
                p[i]--;
                pq.push({values[i][p[i]], i});
            }
            d++;
        }

        return ret;
    }
};
