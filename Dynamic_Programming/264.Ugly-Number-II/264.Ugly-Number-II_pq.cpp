class Solution {
public:
    int nthUglyNumber(int n) 
    {
        priority_queue<long,vector<long>,greater<>>pq;
        pq.push(1);

        for (int t=0; t<n; t++)
        {
            long cur = pq.top();
            pq.pop();
            if (t==n-1) return cur;
            while (!pq.empty() && pq.top()==cur)
                pq.pop();

            if (cur*2 < INT_MAX) pq.push(cur*2);
            if (cur*3 < INT_MAX) pq.push(cur*3);
            if (cur*5 < INT_MAX) pq.push(cur*5);
        }

        return -1;
    }
};
