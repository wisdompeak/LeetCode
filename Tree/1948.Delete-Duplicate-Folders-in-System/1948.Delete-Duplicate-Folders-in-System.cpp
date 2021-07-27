class Solution {
    struct TreeNode {
        string val;
        map<string, TreeNode*> next;  
        TreeNode(string s) : val(s) {}
    };
    TreeNode* root;
    unordered_map<string, int>key2Id;
    unordered_map<string, int>key2count;
    unordered_map<TreeNode*, string> node2key;
    vector<vector<string>>rets;
    
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) 
    {
        root = new TreeNode("/");
        for (auto path: paths)
        {
            TreeNode* node = root;
            for (auto s: path)
            {
                if (node->next.find(s)==node->next.end())
                    node->next[s] = new TreeNode(s);
                node = node->next[s];
            }
        }
        
        getId(root);
        
        vector<string>path;
        dfs(root, path);
        
        return rets;        
    }
    
    int getId(TreeNode* node)
    {
        if (node==NULL)
            return 0;
        
        string key;
        for (auto x: node->next)
        {
            TreeNode* child = x.second;
            key += to_string(getId(child)) + "#" + child->val + "#";
        }
        
        node2key[node] = key;
        
        key2count[key] += 1;
        if (key2count[key]==1)
        {
            key2Id[key] = key2Id.size()+1;
        }
        
        return key2Id[key];
    }
        
    void dfs(TreeNode* node, vector<string>&path)
    {
        string key = node2key[node];
        
        if (key!="" && key2count[key]>=2)
            return;
        
        if (node->val!="/")
        {
            path.push_back(node->val);
            rets.push_back(path);            
        }
        
        for (auto x : node->next)
        {
            dfs(x.second, path);
        }
        
        if (node->val!="/")
        {
            path.pop_back();            
        }        
    }
    
};
