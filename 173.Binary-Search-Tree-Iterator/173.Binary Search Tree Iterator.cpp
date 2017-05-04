/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*>Stack;
    
public:
    BSTIterator(TreeNode *root) 
    {
        while (root!=NULL)
        {
            Stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        if (Stack.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode* node=Stack.top();
        int result = node->val;
        Stack.pop();
        node = node->right;
        while (node!=NULL)
        {
            Stack.push(node);
            node=node->left;
        }
        
        return result;
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
