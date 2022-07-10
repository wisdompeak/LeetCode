class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue<int>pq;
        for (int x: amount)
        {
            if (x!=0)
                pq.push(x);
        }
        int ret = 0;
        while (pq.size()>=2)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ret++;
            if (a-1>0)
                pq.push(a-1);
            if (b-1>0)
                pq.push(b-1);
        }

        if (pq.size()==1)
            ret += pq.top();
        return ret;
        
    }
};
