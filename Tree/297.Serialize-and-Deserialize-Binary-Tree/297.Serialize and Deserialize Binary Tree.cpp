/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    
    string serialize(TreeNode * root) 
    {        
        queue<TreeNode*>q;
        q.push(root);
        string result;
        
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if (node==NULL)
            {
                result+="@#";
            }
            else
            {
                result+= to_string(node->val)+"#";
                q.push(node->left);
                q.push(node->right);
            }
        }        
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) 
    {
        vector<TreeNode*>q;
        
        for (int i=0; i<data.size(); i++)
        {
            if (data[i]=='@')
            {
                q.push_back(NULL);
                i++;
            }
            else
            {
                int i0 = i;
                while (data[i]!='#')
                    i++;
                int num = stoi(data.substr(i0,i-i0));
                TreeNode* node = new TreeNode(num);
                q.push_back(node);
            }
        }
        
        int i = 0;
        int j = 1;        
        while (j<q.size())
        {
            if (q[i]!=NULL)
            {
                q[i]->left = q[j];
                q[i]->right = q[j+1];
                j+=2;
            }            
            i++;
        }        
        return q[0];
    }
};
