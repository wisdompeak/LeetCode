class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        int count = nums.size()-k;
        stack<int>Stack;
        for (int x: nums)
        {
            if (Stack.empty() || x>Stack.top())
            {
                Stack.push(x);
            }
            else
            {
                while (!Stack.empty() && x<Stack.top() && count>0)
                {
                    Stack.pop();
                    count--;
                }
                Stack.push(x);
            }
        }
        while (count>0)
        {
            Stack.pop();
            count--;
        }
        vector<int>ret;
        while (!Stack.empty())
        {
            ret.push_back(Stack.top());
            Stack.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
