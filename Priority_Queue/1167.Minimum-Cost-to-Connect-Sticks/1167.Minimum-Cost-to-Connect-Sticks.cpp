class Solution {
public:
    int connectSticks(vector<int>& sticks) 
    {
        int ret = 0;
        priority_queue<int,vector<int>,greater<>>pq;
        for (int x: sticks)
            pq.push(x);
        
        while (pq.size()>1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ret += a+b;
            pq.push(a+b);
        }
        return ret;
    }
};
