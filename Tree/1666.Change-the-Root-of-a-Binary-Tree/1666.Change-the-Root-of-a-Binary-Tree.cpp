/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        dfs(NULL,leaf);
        return leaf;
    }
    
    void dfs(Node* pre,Node* node)
    {
        if (node==NULL) return;
        
        Node* p=node->parent;
        node->parent=pre;
                
        if (p==NULL)
        {
            if(node->left==pre)
            {
                node->left = NULL;
            }            
            else if(node->right==pre)
            {
                node->right = NULL;
            }            
        }
        else
        {
            if(node->left==pre)
            {
                node->left = p;
            }            
            else if(node->right==pre)
            {
                node->right=node->left;
                node->left = p;
            }
        }
            
        dfs(node,p);
    }
};
