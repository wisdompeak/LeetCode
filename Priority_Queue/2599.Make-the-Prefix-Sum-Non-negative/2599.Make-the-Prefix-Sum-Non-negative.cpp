using LL = long long;
class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) 
    {
        int ret = 0;
        LL sum = 0;
        priority_queue<LL>pq;
        for (int x: nums)
        {
            if (x>=0) 
            {
                sum +=x;
            }
            else if (sum + x >= 0)
            {
                sum +=x;
                pq.push(abs(x));
            }
            else 
            {
                if (!pq.empty() && pq.top() > abs(x))
                {
                    sum = sum + x + pq.top() ;
                    pq.pop();
                    pq.push(abs(x));
                } 
                ret++;
            }
        }
        return ret;
    }
};
