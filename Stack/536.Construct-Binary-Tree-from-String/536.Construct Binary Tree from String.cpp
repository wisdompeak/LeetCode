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
        if (s=="") return NULL;
        
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
                if (Stack.top()->left==NULL)
                    Stack.top()->left=current;
                else
                    Stack.top()->right=current;
                current = Stack.top();
                Stack.pop();
            }
            else
            {
                int i0=i;
                while (s[i]!='(' && s[i]!=')')
                    i++;
                current = new TreeNode(stoi(s.substr(i0,i-i0)));
                i--;
            }
        }
        
        return current;
    }
};
