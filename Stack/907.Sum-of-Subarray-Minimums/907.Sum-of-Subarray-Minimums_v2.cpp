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
            while (!Stack.empty() && arr[Stack.top()] > arr[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            
            if (!Stack.empty())
                prevSmaller[i] = Stack.top();
            Stack.push(i);
        }
        
        
        long ret = 0;
        long M = 1e9+7;
        for (int i=0; i<n; i++)
        {
            int a = prevSmaller[i];
            int b = nextSmaller[i];
            long num = arr[i]*(i-a) % M *(b-i) % M;
            ret = (ret + num) % M;            
        }
        return ret;
    }
};
