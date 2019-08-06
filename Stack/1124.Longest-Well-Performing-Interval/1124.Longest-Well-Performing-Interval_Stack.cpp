class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        vector<int>presum({0});
        int sum = 0;
        for (int x: hours)
        {
            if (x>8)
                sum+=1;
            else
                sum+=-1;
            presum.push_back(sum);
        }
        
        stack<int>Stack;
        for (int i=0; i<presum.size(); i++)
        {
            if (Stack.empty() || presum[Stack.top()] > presum[i])
                Stack.push(i);
        }
        
        int result = 0;
        for (int j = presum.size()-1; j>=0; j--)
        {
            while (!Stack.empty() && presum[Stack.top()] < presum[j])
            {
                result = max(result, j - Stack.top());
                Stack.pop();
            }   
        }
        return result;        
    }
};
