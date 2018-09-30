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
        vector<string>q;
        for (int i=0; i<data.size(); i++)
        {
            int j=i;
            while (j<data.size() && data[j]!=',')
                j++;
            q.push_back(data.substr(i,j-i));
            i=j;
        }
        return DFS(q,0);
    }
    
    TreeNode* DFS(vector<string>&q, int a)
    {
        if (q[a]=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(q[a]));
        TreeNode* left = DFS(q,a+1);
        int leftSize = getSize(left);
        TreeNode* right = DFS(q,a+1+leftSize);        
        root->left = left;
        root->right = right;
        return root;
    }
    
    int getSize(TreeNode* node)
    {
        if (node==NULL) return 1;
        return getSize(node->left)+1+getSize(node->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
