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
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        if (n == 0) return {};
        return generateTreesDFS(1,n);
    }
    
    vector<TreeNode*> generateTreesDFS(int start, int end) 
    {
         vector<TreeNode*> subTree;
         
         if (start>end)
         {
             subTree.push_back(NULL);
         }
         else
         {
             for (int i=start; i<=end; i++)
             {
                vector<TreeNode*> leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> rightSubTree = generateTreesDFS(i + 1, end);
             
            
                for (int j = 0; j < leftSubTree.size(); ++j) 
                    for (int k = 0; k < rightSubTree.size(); ++k) 
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = (leftSubTree)[j];
                        node->right = (rightSubTree)[k];
                        subTree.push_back(node);
                    }
            }             
         }
         
         return subTree;
    }

};
