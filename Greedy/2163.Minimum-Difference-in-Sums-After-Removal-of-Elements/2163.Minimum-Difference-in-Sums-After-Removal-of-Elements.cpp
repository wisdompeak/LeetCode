using LL = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size()/3;
        
        vector<LL>leftMin(3*n); 
        priority_queue<int>pq;
        LL sum = 0;
        for (int i=0; i<3*n; i++)
        {
            pq.push(nums[i]);
            sum += nums[i];
            if (pq.size() > n)
            {
                sum -= pq.top();
                pq.pop();
            }
            leftMin[i] = sum;            
        }
        
        vector<LL>rightMax(3*n);
        priority_queue<int, vector<int>, greater<>>pq2;
        sum = 0;
        for (int i=3*n-1; i>=0; i--)
        {
            pq2.push(nums[i]);
            sum += nums[i];
            if (pq2.size() > n)
            {
                sum -= pq2.top();
                pq2.pop();
            }
            rightMax[i] = sum;            
        }
        
        LL ret = LLONG_MAX;
        for (int i=n-1; i<2*n; i++)
            ret = min(ret, leftMin[i]-rightMax[i+1]);
            
        return ret;        
    }
};

