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
        if (root==NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        cout<<data<<endl;
        queue<string>q;
        for (int i=0; i<data.size(); i++)
        {
            int j=i;
            while (j<data.size() && data[j]!=',')
                j++;
            q.push(data.substr(i,j-i));
            i=j;
        }
        return DFS(q);
    }
    
    TreeNode* DFS(queue<string>&q)
    {
        string cur = q.front();
        q.pop();
        
        if (cur=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(cur));
        
        TreeNode* left = DFS(q);        
        TreeNode* right = DFS(q);
        root->left = left;
        root->right = right;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
