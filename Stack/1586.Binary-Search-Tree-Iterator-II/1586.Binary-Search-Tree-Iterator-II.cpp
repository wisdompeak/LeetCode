/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<pair<TreeNode*,bool>>nexts;
    stack<TreeNode*>visited;
public:
    BSTIterator(TreeNode* root) 
    {
        TreeNode* p = root;
        while (p)
        {
            nexts.push({p,true});
            p = p->left;
        }
    }
    
    bool hasNext() 
    {
        return !nexts.empty();        
    }
    
    int next() 
    {
        auto [node, flag] = nexts.top();
        nexts.pop();
        
        if (flag == 1)
        {
            TreeNode* p = node->right;
            while (p)
            {
                nexts.push({p, true});
                p = p->left;
            }
        }
            
        visited.push(node);
        return node->val;
    }
    
    bool hasPrev() 
    {
        return visited.size() > 1;
    }
    
    int prev() 
    {
        nexts.push({visited.top(), false});
        visited.pop();
        
        return visited.top()->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
