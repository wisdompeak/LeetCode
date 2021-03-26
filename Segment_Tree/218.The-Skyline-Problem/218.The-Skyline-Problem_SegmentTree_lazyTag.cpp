class Solution {
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;       
        int tag;
        SegTreeNode(int a, int b):start(a),end(b),info(0),tag(0),left(NULL),right(NULL){}
    };
    
    void init(SegTreeNode* node, int a, int b)  // init for range [a,b]
    {                        
        if (a==b)
        {
            node->info = 0;
            return;
        }
        int mid = (a+b)/2;
        if (node->left==NULL)
        {
            node->left = new SegTreeNode(a, mid);
            node->right = new SegTreeNode(mid+1, b);
        }
        init(node->left, a, mid);
        init(node->right, mid+1, b);                
    }
    
    void updateRange(SegTreeNode* node, int a, int b, int val)
    {        
        if (b < node->start || a > node->end ) // no intersection
            return;
        if (node->start == node->end)   // leaf node
        {
            node->info = max(node->info, val);
            node->tag = 0;
            return;
        }
        if (a <= node->start && node->end <=b && node->info <= val) // no need to dive, tag lazy
        {            
            node->info = val;
            node->tag = 1;
            return;
        }        
        
        if (node->tag == 1) // if current node tagged lazy, push information down
        {
            node->tag = 0;            
            node->left->info = node->info;
            node->right->info = node->info;
            node->left->tag = 1;
            node->right->tag = 1;            
        }        
        node->info = max(node->info, val);
        
        updateRange(node->left, a, b, val);
        updateRange(node->right, a, b, val);        
    }
        
    SegTreeNode* root;
    vector<vector<int>>arr;
    
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        set<int>Set;
        for (auto& building: buildings)
        {
            Set.insert(building[0]);
            Set.insert(building[1]);
        }
        int i = 0;
        unordered_map<int,int>pos2idx;
        vector<int>idx2pos;
        for (auto x: Set)
        {
            pos2idx[x] = i;
            idx2pos.push_back(x);
            i++;
        }
        
        int n = pos2idx.size();
        SegTreeNode* root = new SegTreeNode(0, n-1);
        init(root, 0, n-1);
        
        for (auto & building : buildings)
        {
            updateRange(root, pos2idx[building[0]], pos2idx[building[1]]-1, building[2]);
        }
        
        DFS(root);
        
        vector<vector<int>>rets;
        for (int i=0; i<arr.size(); i++)
        {
            rets.push_back({idx2pos[arr[i][0]], arr[i][1]});
            while (i+1 < arr.size() && arr[i+1][1]==arr[i][1])
            {
                i++;
            }
        }
        return rets;
    }
    
    void DFS(SegTreeNode* node)
    {
        if (node->start == node->end || node->tag == 1)
        {
            arr.push_back({node->start, node->info});            
        }
        else
        {
            DFS(node->left);
            DFS(node->right);                    
        }
        
    }
    
};
