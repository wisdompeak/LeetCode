typedef pair<int,int> PII;
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) 
    {
        int n = nums.size();
        priority_queue<PII>pq;
        for (int i=0; i<n; i++)
            pq.push({nums[i],i});
        
        vector<int>nextSmaller(n, n);
        vector<int>prevSmaller(n, -1);
            
        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && nums[Stack.top()] > nums[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && nums[Stack.top()] >= nums[i])
            {
                prevSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        vector<int>rets;    
        for (int k=1; k<=n; k++)
        {                
            while (1)
            {
                if (pq.empty()) break;
                int p = pq.top().second;
                if (nextSmaller[p] - prevSmaller[p] -1 >= k)
                    break;
                pq.pop();
            }
            rets.push_back(pq.top().first);
        }
        
        return rets;

    }
};
