using LL = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size()/3;                
                        
        LL sum = 0;        
        vector<LL>leftMin(3*n);                       
        priority_queue<int>pq;
        for (int i=0; i<2*n; i++)
        {            
            pq.push(nums[i]);
            sum += nums[i];
            if (i>=n)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (i>=n-1)
                leftMin[i] = sum;
            else if (i>n-1)
                leftMin[i] = min(leftMin[i-1], sum);
        }
        
        sum = 0;        
        priority_queue<int,vector<int>,greater<>>pq2;
        vector<LL>rightMax(3*n);  
        for (int i=3*n-1; i>=n; i--)
        {
            pq2.push(nums[i]);
            sum += nums[i];
            if (i<=2*n-1)
            {
                sum -= pq2.top();
                pq2.pop();
            }
            if (i==2*n)
                rightMax[i] = sum;
            else if (i<2*n)
                rightMax[i] = max(rightMax[i+1], sum);            
        }            
        
        LL ret = LLONG_MAX;
        for (int i=n-1; i<2*n; i++)
            ret = min(ret, leftMin[i]-rightMax[i+1]);
        return ret;
    }
};
