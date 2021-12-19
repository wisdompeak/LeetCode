class Solution {
    unordered_map<int,int>nextGreater;
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums2.size();
        stack<int>Stack;  // index
        for (int i = 0; i < n; i++)
        {
            while (!Stack.empty() && nums2[Stack.top()] < nums2[i])
            {
                nextGreater[nums2[Stack.top()]] = nums2[i];
                Stack.pop();
            }
            Stack.push(i);
        }
        
        vector<int>rets;
        for (int x: nums1)
        {
            if (nextGreater.find(x)==nextGreater.end())
                rets.push_back(-1);
            else
                rets.push_back(nextGreater[x]);
        }
        return rets;        
    }
};
