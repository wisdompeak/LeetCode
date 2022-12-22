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
    unordered_map<int,vector<int>>adj;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        if (K==0) return {target->val};        
        
        DFS(root);
        
        queue<pair<int,int>>q;
        unordered_set<int>visited;
      
        q.push({target->val,0});
        visited.insert(target->val);
        
        vector<int>results;
        while (!q.empty())
        {
            auto [cur, step] = q.front();
            q.pop();
            if (step>K) break;
            
            for (int next: adj[cur])
            {
                if (visited.find(next)!=visited.end())
                    continue;                    
                q.push({next,step+1});
                visited.insert(next);
                
                if (step+1==K) results.push_back(next);
            }
        }
        return results;
    }
    
    void DFS(TreeNode* node)
    {
        if (node==NULL) return;
        if (node->left!=NULL)
        {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            DFS(node->left);
        }
        if (node->right!=NULL)
        {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            DFS(node->right);
        }            
    }
};
