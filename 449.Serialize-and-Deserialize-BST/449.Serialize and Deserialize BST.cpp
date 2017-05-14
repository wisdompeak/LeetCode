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
        string s;
        DFS(root,s);
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data.size()==0) return NULL;
        vector<int>preorder;
        int i=0;
        while (i<data.size())
        {
            string s="";
            while (data[i]!=',')
            {
                s+=data[i];
                i++;
            }
            preorder.push_back(stoi(s));
            i++;
        }
        
        for (int i=0; i<preorder.size(); i++)
            cout<<preorder[i]<<" ";
        cout<<endl;
        
        TreeNode *root = DFS2(preorder,0,INT_MIN,INT_MAX);
        
        return root;
    }
    
private:
    void DFS(TreeNode* root, string& s)
    {
        if (root==NULL) return;
        
        s+=to_string(root->val)+',';
        DFS(root->left,s);
        DFS(root->right,s);
    }
    
    TreeNode* DFS2(vector<int>& preorder,int curIdx, int MIN, int MAX)
    {
        if (curIdx>=preorder.size()) return NULL;
        
        if (preorder[curIdx]<MIN || preorder[curIdx]>MAX)
            return DFS2(preorder, curIdx+1, MIN, MAX);
        
        TreeNode* root = new TreeNode(preorder[curIdx]);
        root->left = DFS2(preorder,curIdx+1,MIN,root->val);
        root->right = DFS2(preorder,curIdx+1,root->val,MAX); 
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
