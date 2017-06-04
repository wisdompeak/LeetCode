/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        TreeLinkNode* now=root;
        TreeLinkNode* head=NULL;
        TreeLinkNode* tail=NULL;
        
        while (now!=NULL)
        {
            if (now->left!=NULL)
            {
                if (head==NULL) head=now->left;
                if (tail==NULL) 
                    tail=now->left;
                else
                {
                    tail->next = now->left;
                    tail=tail->next;
                }
            }
            if (now->right!=NULL)
            {
                if (head==NULL) head=now->right;
                if (tail==NULL) 
                    tail=now->right;
                else
                {
                    tail->next = now->right;
                    tail=tail->next;
                }
            }            
            now=now->next;
            if (now==NULL)
            {
                now=head;
                head=NULL;
                tail=NULL;
            }
        }
    }
};
