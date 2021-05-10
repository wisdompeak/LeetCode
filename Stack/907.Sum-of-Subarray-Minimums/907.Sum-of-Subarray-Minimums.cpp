class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();        
        vector<int>nextSmaller(n, n);        
        vector<int>prevSmaller(n, -1);

        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && arr[Stack.top()]>arr[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);                    
        }
                
        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && arr[Stack.top()]>=arr[i])
            {
                prevSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i); 
        }

        long ret = 0;
        long M = 1e9+7;
        for (int i=0; i<n; i++)
        {
            long count = (i-prevSmaller[i])*(nextSmaller[i]-i) % M;
            ret = (ret+arr[i]*count) %M;
        }
        return ret;
    }
};
