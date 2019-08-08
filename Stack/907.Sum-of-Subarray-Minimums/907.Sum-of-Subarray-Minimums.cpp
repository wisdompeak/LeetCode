class Solution {
public:
    int sumSubarrayMins(vector<int>& A) 
    {
        int n = A.size();
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);
        for (int i=0; i<n; i++)
        {
            prevSmaller[i] = -1;
            nextSmaller[i] = n;
        }
        
        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && A[Stack.top()] > A[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        while (!Stack.empty()) Stack.pop();
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && A[Stack.top()] > A[i])
                    Stack.pop();
            
            if (!Stack.empty()) prevSmaller[i] = Stack.top();
                Stack.push(i);
        }
                
        long result = 0;
        long M = 1e9+7;
        for (int i=0; i<n; i++)
        {
            long times = (i - prevSmaller[i])*(nextSmaller[i] - i);
            result += A[i]*times;
            result = result%M;
        }
        
        return result;        
    }
};
