/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<string,vector<TreeNode*>>Map;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        DFS(root);
        vector<TreeNode*>results;
        for (auto a:Map)
        {
            if (a.second.size()>1)
                results.push_back(a.second[0]);
        }
        return results;        
    }
    
    void DFS(TreeNode* node)
    {
        if (node==NULL)
            return;
        Map[serialize(node)].push_back(node);
        DFS(node->left);
        DFS(node->right);        
    }
    
    string serialize(TreeNode* node)
    {        
        queue<TreeNode*>q;
        q.push(node);
        string result;
        
        while (!q.empty())
        {            
            if (q.front()==NULL)
            {
                q.pop();
                result+="#,";                
            }
            else
            {
                result+=to_string(q.front()->val);
                result+=",";
                q.push(q.front()->left);
                q.push(q.front()->right);
                q.pop();                
            }
        }
        return result;
    }
};
