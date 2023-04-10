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
                continue;
            }

            if (sum+x < 0)
            {
                if (!pq.empty() && pq.top() > abs(x))
                {
                    sum = sum + pq.top() + x;
                    pq.pop();
                    pq.push(abs(x));
                    ret++;
                } 
                else 
                {
                    ret++;
                }
            }
            else
            {
                sum +=x;
                pq.push(abs(x));
            }                
        }
        return ret;
    }
};
