class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) 
    {
        stack<int>Stack;
        int small=INT_MIN;
        for (int i=0; i<preorder.size(); i++)
        {
            if (preorder[i]<small) return false;
            
            while (!Stack.empty() && preorder[i]>Stack.top())
            {
                small=Stack.top();
                Stack.pop();
            }
            Stack.push(preorder[i]);              
        }
        return true;
    }
};
