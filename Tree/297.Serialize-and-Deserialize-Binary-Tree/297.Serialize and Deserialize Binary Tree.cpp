/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        string ret;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node!=NULL)
            {
                ret+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else
                ret+="#,";
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<TreeNode*>nodes;
        for (int i=0; i<data.size(); i++)
        {
            int j = i;
            while (j<data.size() && data[j]!=',')
                j++;
            string str = data.substr(i,j-i);
            if (str=="#")
                nodes.push_back(NULL);
            else
                nodes.push_back(new TreeNode(stoi(str)));
            i = j;
        }

        int i = 0,  j = 1;
        while (j<nodes.size())
        {
            if (nodes[i]!=NULL)
            {
                nodes[i]->left = nodes[j];
                nodes[i]->right = nodes[j+1];
                j+=2;
            }
            i++;
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
