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
        else return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);        
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

        return DFS(nodes, 0);
    }

    TreeNode* DFS(vector<TreeNode*>&nodes, int cur)
    {
        if (nodes[cur]==NULL) return NULL;

        TreeNode* left = DFS(nodes, cur+1);
        int leftSize = getNum(left);
        TreeNode* right = DFS(nodes, cur+leftSize+1);
        nodes[cur] -> left = left;
        nodes[cur] -> right = right;
        return nodes[cur];
    }

    int getNum(TreeNode* node)
    {
        if (node==NULL) return 1;
        else return getNum(node->left)+getNum(node->right)+1;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// 1,[2,#,#],[3,4,#,#,5,#,#],
