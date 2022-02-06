using LL = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size()/3;                
                        
        LL rollingSum = 0;
        vector<LL>leftMin(3*n);                       
        priority_queue<int>pq;
        for (int i=0; i<2*n; i++)
        {            
            pq.push(nums[i]);
            rollingSum += nums[i];
            if (pq.size() > n)
            {
                rollingSum -= pq.top();
                pq.pop();
            }
            if (pq.size() == n)            
                leftMin[i] = rollingSum;            
        }
        
        rollingSum = 0;
        priority_queue<int,vector<int>,greater<>>pq2;
        vector<LL>rightMax(3*n);  
        for (int i=3*n-1; i>=n; i--)
        {
            pq2.push(nums[i]);
            rollingSum += nums[i];
            if (i<=2*n-1)
            {
                rollingSum -= pq2.top();
                pq2.pop();
            }
            if (pq.size() == n)
                rightMax[i] = rollingSum;
        }            
        
        LL ret = LLONG_MAX;
        for (int i=n-1; i<2*n; i++)
            ret = min(ret, leftMin[i]-rightMax[i+1]);
        return ret;
    }
};
