class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        if (preorder.size()<=1) return true;
        
        stack<int>Stack;
        Stack.push(preorder[0]);
        int small = INT_MIN;

        for (int i=1; i<preorder.size(); i++)
        {
            if (preorder[i]<small) return false;
            
            while (!Stack.empty() && preorder[i]>Stack.top())
            {
                small=max(small,Stack.top());
                Stack.pop();
            }
            
            Stack.push(preorder[i]);
        }
        
        return true;
    }
};
