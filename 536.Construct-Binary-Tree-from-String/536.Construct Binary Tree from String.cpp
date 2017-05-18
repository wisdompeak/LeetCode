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
    TreeNode* str2tree(string s) 
    {
        stack<TreeNode*>Stack;
        TreeNode* current=NULL;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                Stack.push(current);
                current=NULL;
            }
            else if (s[i]==')')
            {
                TreeNode* node=Stack.top();
                Stack.pop();
                if (node->left==NULL)
                    node->left=current;
                else
                    node->right=current;
                current=node;
            }
            else
            {
                int sign=1;
                if (s[i]=='-')
                {
                    sign=-1;
                    i++;
                }
                int num=0;
                while (i<s.size() && s[i]>='0' && s[i]<='9')
                {
                    num = num*10+s[i]-'0';
                    i++;
                }
                i--;
                num = num*sign;
                current = new TreeNode(num);
            }
        }
        return current;
    }
};
