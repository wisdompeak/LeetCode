class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        int n = heights.size();

        stack<int>s;
        vector<int>nextGreater(n, n);
        for (int i = 0; i< n; i++) 
        {            
            while (!s.empty() && heights[i] > heights[s.top()]) 
            {
                nextGreater[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
 
        vector<int>rets(n);
        for (int i = 0; i < n; i++) 
        {
            int count = 0;
            int j = i+1;
            while (j<n && j<= nextGreater[i])
            {
                count++;
                j = nextGreater[j];
            }
            rets[i] = count;
        }
        return rets;

    }
};
