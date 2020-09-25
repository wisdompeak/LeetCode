/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) 
    {
        if (s.size()==1)
        {
            Node* root = new Node(s[0]);
            return root;
        }
        
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='+' || s[i]=='-')
            {
                Node* root = new Node(s[i]);
                root->right = expTree(s.substr(i+1));
                root->left = expTree(s.substr(0,i));                
                return root;
            }            
            else if (s[i]==')')
            {
                int j = i-1;
                int count = 1;
                while (j>=0 && count>0)
                {
                    if (s[j]==')')
                        count++;
                    else if (s[j]=='(')
                        count--;
                    j--;
                }
                i = j+1;
            }
        }
        
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='*' || s[i]=='/')
            {
                Node* root = new Node(s[i]);
                root->right = expTree(s.substr(i+1));
                root->left = expTree(s.substr(0,i));                
                return root;
            }            
            else if (s[i]==')')
            {
                int j = i-1;
                int count = 1;
                while (j>=0 && count>0)
                {
                    if (s[j]==')')
                        count++;
                    else if (s[j]=='(')
                        count--;
                    j--;
                }
                i = j+1;
            }
        }
        
        if (s[0]=='(' && s.back()==')')
            return expTree(s.substr(1, s.size()-2));
        
        return NULL;                
    }
};
