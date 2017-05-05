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
        string result;
        while (!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            if (node==NULL)
                result+='#';
            else
            {
                result+=to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            result+=',';
        }
        cout<<result<<endl;
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {

        vector<string>q;
        
        int i=0;
        int j=0;
        while (i<data.size())
        {
            if (data[i]==',')
            {
                i++;
                continue;
            }
            else
            {
                string temp;
                while (data[i]!=',')
                {
                    temp+=data[i];
                    i++;
                }
                q.push_back(temp);
            }
        }
        
        for (int i=0; i<q.size(); i++)
            cout<<q[i]<<" ";
        cout<<endl;
            
        TreeNode* root;;
        vector<TreeNode*>nodeArray(q.size());
        
        if (q[0]=="#")
            nodeArray[0]= NULL;
        else
            nodeArray[0]= new TreeNode(stoi(q[0],nullptr,10));
        
        i=0;
        j=1;
        while (i<q.size())
        {
            if (q[i]=="#")
            {
                i++;
                continue;
            }
            else
            {
                if (q[j]=="#")
                {
                    nodeArray[j] = NULL;
                }
                else
                {
                    int val;
                    val = stoi(q[j],nullptr,10);
                    nodeArray[j] = new TreeNode(val);
                }
                nodeArray[i]->left = nodeArray[j];
                j++;
                
                if (q[j]=="#")
                {
                    nodeArray[j] = NULL;
                }
                else
                {
                    int val;
                    val = stoi(q[j],nullptr,10);
                    nodeArray[j] = new TreeNode(val);
                }
                nodeArray[i]->right = nodeArray[j];
                j++;
                
                i++;
            }
        }
        
        return nodeArray[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
